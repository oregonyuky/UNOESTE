const urlBase = 'http://localhost:4000/livros';
const vitrine = document.getElementById('vitrine');
const filtro = document.getElementById('filtroCategoria');
let listaDeLivros = [];
function criarCardLivro(livro) {
    const card = document.createElement('div');
    const info = document.createElement('div');
    info.innerHTML = `
        <h3>${livro.titulo}</h3>
        <p>Edição: ${livro.edicao}</p>
        <p>Categoria: ${livro.categoria}</p>
    `;
    const botoes = document.createElement('div');
    const btnGostei = document.createElement('button');
    btnGostei.textContent = 'Gostei';
    const btnNaoGostei = document.createElement('button');
    btnNaoGostei.textContent = 'Não Gostei';
    botoes.appendChild(btnGostei);
    botoes.appendChild(btnNaoGostei);
    const avaliacoes = JSON.parse(localStorage.getItem('avaliacoes') || '{}');
    if (avaliacoes[livro.id]) {
        btnGostei.disabled = true;
        btnNaoGostei.disabled = true;
    }
    btnGostei.onclick = () => votarLivro(livro.id, true);
    btnNaoGostei.onclick = () => votarLivro(livro.id, false);
    card.appendChild(info);
    card.appendChild(botoes);
    return card;
}
function mostrarLivros(lista) {
    vitrine.innerHTML = '';
    if (lista.length === 0) {
        vitrine.innerHTML = '<p>Nenhum título encontrado.</p>';
        return;
    }
    lista.forEach(livro => {
        const card = criarCardLivro(livro);
        vitrine.appendChild(card);
    });
}
function votarLivro(id, gostou) {
    const livro = listaDeLivros.find(l => l.id === id);
    if (!livro) return;
    const campo = gostou ? 'contador_gostei' : 'contador_naogostei';
    const novoValor = (livro[campo] || 0) + 1;
    fetch(`${urlBase}/${id}`, {
        method: 'PATCH',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ [campo]: novoValor })
    })
    .then(res => {
        if (!res.ok) throw new Error('Erro ao votar');
        return res.json();
    })
    .then(() => {
        const avaliacoes = JSON.parse(localStorage.getItem('avaliacoes') || '{}');
        avaliacoes[id] = true;
        localStorage.setItem('avaliacoes', JSON.stringify(avaliacoes));
        obterLivros();
    })
    .catch(() => alert('Erro ao enviar seu voto.'));
}
function filtrarLivros() {
    const categoria = filtro.value;
    if (!categoria) {
        mostrarLivros(listaDeLivros);
    } else {
        mostrarLivros(listaDeLivros.filter(l => l.categoria === categoria));
    }
}
function obterLivros() {
    fetch(urlBase)
    .then(res => res.json())
    .then(livros => {
        listaDeLivros = livros;
        filtrarLivros();
    })
    .catch(() => {
        vitrine.innerHTML = '<p>Erro ao carregar os livros.</p>';
    });
}
filtro.onchange = filtrarLivros;
obterLivros();
