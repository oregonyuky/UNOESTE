const urlBase = "http://localhost:4000/salas";
function listarFilmes() {
    fetch(urlBase, {method: "GET"})
        .then((response) => response.json())
        .then((salas) => {
            let filmes = salas;
            let filmesHtml = "";
            for (let i = 0; i < filmes.length; i++) {
                filmesHtml += `
                <div class="card mt-3 mb-3" style="width: 18rem;">
                    <img src="${filmes[i].imagem}" class="card-img-top" alt="${filmes[i].filme}">
                    <div class="card-body">
                        <h5 class="card-title">${filmes[i].filme}</h5>
                        <p class="card-text">${filmes[i].sessoes}</p>
                        <p class="card-text">Assentos Vendidos: ${renderizarAssentosVendidos(filmes[i].assentosVendidos.sort())}</p>
                    </div>
                    <button class="btn btn-success" onclick="window.location.href='/comprar?id=${filmes[i].id}'">Comprar Ingresso</button>
                </div>
                `;
            }
            document.getElementById("filmes").innerHTML = filmesHtml;
        });
}

function renderizarAssentosVendidos(assentosVendidos) {
    let assentosVendidosHtml = "";
    for (i = 0; i < assentosVendidos.length; i++) {
        assentosVendidosHtml += `<div><img class="assentoPequeno" src="/imagens/AssentoOcupado.png" alt="Assento Vendido">${assentosVendidos[i]}</div>`;
    }
    return "<div class='gradeAssentosVendidos'>" + assentosVendidosHtml + "</div>";
}
listarFilmes();