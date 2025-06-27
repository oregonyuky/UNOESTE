let selecionado = null;
function obter(nome) {
    const q = window.location.search.substring(1); 
    const p = q.split("&");
    for (let i = 0; i < p.length; i++) {
      const pa = p[i].split("=");
      if (pa[0] === nome) {
        return pa[1] || "";
      }
    }
    return null;
  }
window.onload = function () {
  const id = obter("id");
  fetch(`http://localhost:4000/salas`)
    .then((res) => res.json())
    .then((salas) => {
      const filme = salas.find(f => f.id == id);
      if (!filme) return alert("Filme não encontrado");
      const container = document.getElementById("filme-info");
      container.innerHTML = `
        <h3>${filme.filme}</h3>
        <img src="${filme.imagem}" style="max-height: 300px;"><br><br>
        <div style="background: #ccc; padding: 5px;">Tela</div>
        <div id="mapaAssentos" style="display: grid; grid-template-columns: repeat(5, 60px); gap: 10px; justify-content: center;"></div>
      `;
      const mapa = document.getElementById("mapaAssentos");
      const fileiras = ["A", "B", "C", "D", "E"];
      const numeros = ["1", "2", "3", "4", "5"];
      for (let f = 0; f < fileiras.length; f++) {
        for (let n = 0; n < numeros.length; n++) {
          const assento = fileiras[f] + numeros[n];
          const ocupado = filme.assentosVendidos.includes(assento);
          const img = document.createElement("img");
          img.setAttribute("src", ocupado ? "/imagens/assentoOcupado.png" : "/imagens/assentoLivre.png");
          img.setAttribute("data-assento", assento);
          img.setAttribute("class", "assento " + (ocupado ? "ocupado" : "livre"));
          img.style.width = "50px";
          img.style.cursor = ocupado ? "default" : "pointer";
          if (!ocupado) {
            img.onclick = function () {
              if (selecionado) {
                selecionado.src = "/imagens/assentoLivre.png";
              }
              img.src = "/imagens/assentoOcupado.png";
              selecionado = img;
              document.getElementById("assentoEscolhido").value = assento;
            };
          }
          mapa.appendChild(img);
        }
      }
      const selectSessao = document.getElementById("sessao");
      for (let i = 0; i < filme.sessoes.length; i++) {
        const opt = document.createElement("option");
        opt.value = filme.sessoes[i];
        opt.text = filme.sessoes[i];
        selectSessao.appendChild(opt);
      }
      const botao = document.getElementById("btnConfirmar");
      botao.onclick = async function () {
        const RA = document.getElementById("ra").value;
        const assento = document.getElementById("assentoEscolhido").value;
        const sessao = document.getElementById("sessao").value;
        if (!RA || !assento || !sessao) {
          alert("Preencha todos os campos!");
          return;
        }
        await fetch("http://localhost:4000/salas", {
          method: "PUT",
          headers: { "Content-Type": "application/json" },
          body: JSON.stringify({ filme_id: parseInt(id), assento })
        });
        await fetch("http://localhost:4000/vendas", {
          method: "POST",
          headers: { "Content-Type": "application/json" },
          body: JSON.stringify({
            id: Date.now(),
            RA,
            filme_id: parseInt(id),
            sessao,
            assento
          })
        });
        alert("Compra realizada com sucesso!");
        window.location.href = "index.html";
      };
    });
};
