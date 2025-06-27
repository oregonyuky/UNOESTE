const urlBase = 'http://localhost:4000/livros';

const formulario = document.getElementById("formCadLivros");
let listaDeLivros = [];

formulario.onsubmit = manipularSubmissao;
localStorage.clear();
function manipularSubmissao(evento) {
    if (formulario.checkValidity()) {
        const titulo = document.getElementById("titulo").value;
        const url_capa = document.getElementById("url_capa").value;
        const autor = document.getElementById("autor").value;
        const edicao = document.getElementById("edicao").value;
        const categoria = document.getElementById("categoria").value;
        const descricao = document.getElementById("descricao").value;

        const livro = { 
            titulo, 
            url_capa, 
            autores: autor, 
            edicao, 
            categoria, 
            descricao,
            contador_gostei: 0,
            contador_naogostei: 0
        };

        cadastrarLivro(livro);
        formulario.reset();
        mostrarTabelaLivros();
    } else {
        formulario.classList.add('was-validated');
    }

    evento.preventDefault();
    evento.stopPropagation();
}

function mostrarTabelaLivros() {
    const divTabela = document.getElementById("tabelaL");
    if (!divTabela) return;

    divTabela.innerHTML = "";

    if (listaDeLivros.length === 0) {
        divTabela.innerHTML = "<p class='alert alert-info text-center'>Não há livros cadastrados</p>";
    } else {
        const tabela = document.createElement('table');
        tabela.className = "table table-striped table-hover";
        
        const cabecalho = document.createElement('thead');
        const corpo = document.createElement('tbody');

        cabecalho.innerHTML = `
            <tr>
                <th>Título</th>
                <th>Autor</th>
                <th>Edição</th>
                <th>Categoria</th>
                <th>Descrição</th>
                <th>Rating</th>
                <th>Ações</th>
            </tr>
        `;
        tabela.appendChild(cabecalho);

        for (let livro of listaDeLivros) {
            const linha = document.createElement('tr');
            linha.id = livro.id;

            const total = livro.contador_gostei + livro.contador_naogostei;
            const rating = total > 0 ? ((livro.contador_gostei / total) * 5).toFixed(2) : "Sem avaliação";

            linha.innerHTML = `
                <td>${livro.titulo}</td>
                <td>${livro.autores}</td>
                <td>${livro.edicao}</td>
                <td>${livro.categoria}</td>
                <td>${livro.descricao}</td>
                <td>${rating}</td>
                <td>
                    <button onclick="gostei('${livro.id}')">Gostei</button>
                    <button onclick="naoGostei('${livro.id}')">Não Gostei</button>
                    <button onclick="excluirLivro('${livro.id}')">Excluir</button>
                </td>
            `;

            const avaliacoes = JSON.parse(localStorage.getItem("avaliacoes") || "{}");
            if (avaliacoes[livro.id]) {
                const botoes = linha.querySelectorAll('button');
                botoes[0].disabled = true;
                botoes[1].disabled = true;
            }

            corpo.appendChild(linha);
        }

        tabela.appendChild(corpo);
        divTabela.appendChild(tabela);
    }
}

function gostei(id) {
    const livro = listaDeLivros.find(l => l.id === id);
    if (!livro) return;

    fetch(`${urlBase}/${id}`, {
        method: "PATCH",
        headers: {"Content-Type": "application/json"},
        body: JSON.stringify({contador_gostei: livro.contador_gostei + 1})
    })
    .then(() => {
        marcarComoAvaliado(id);
        obterDadosLivros();
    });
}

function naoGostei(id) {
    const livro = listaDeLivros.find(l => l.id === id);
    if (!livro) return;

    fetch(`${urlBase}/${id}`, {
        method: "PATCH",
        headers: {"Content-Type": "application/json"},
        body: JSON.stringify({contador_naogostei: livro.contador_naogostei + 1})
    })
    .then(() => {
        marcarComoAvaliado(id);
        obterDadosLivros();
    });
}

function marcarComoAvaliado(id) {
    const avaliacoes = JSON.parse(localStorage.getItem("avaliacoes") || "{}");
    avaliacoes[id] = true;
    localStorage.setItem("avaliacoes", JSON.stringify(avaliacoes));
}

function excluirLivro(id) {
    if (confirm("Deseja realmente excluir o livro?")) {
        fetch(urlBase + "/" + id, {
            method: "DELETE"
        })
        .then(() => {
            listaDeLivros = listaDeLivros.filter(l => l.id !== id);
            document.getElementById(id)?.remove();
        });
    }
}

function obterDadosLivros() {
    fetch(urlBase)
    .then(res => res.json())
    .then(livros => {
        listaDeLivros = livros;
        mostrarTabelaLivros();
    })
    .catch(() => {
        alert("Erro ao tentar recuperar livros do servidor!");
    });
}

function cadastrarLivro(livro) {
    fetch(urlBase, {
        method: "POST",
        headers: {
            "Content-Type": "application/json",
        },
        body: JSON.stringify(livro)
    })
    .then(res => res.json())
    .then(dados => {
        livro.id = dados.id;
        listaDeLivros.push(livro);
        mostrarTabelaLivros();
    });
}

obterDadosLivros();
