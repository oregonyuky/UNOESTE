const palavra = 'UNOESTE';
const qtd = palavra.length;
const c1 = window.innerWidth / 2;
const c2 = window.innerHeight /2;

function plotarMensagem(){
    for (let i=0; i<qtd; i++){
        const letra = document.createElement('p');
        letra.innerHTML=palavra[i];
        letra.style.position='absolute';
        letra.style.fontFamily='Arial';
        letra.style.fontStyle='bold';
        letra.style.fontSize='50px';
        letra.style.color='green';
        letra.id='letra' + i;
        document.body.appendChild(letra);        
    }
}

function movimentar(){
    for (let i=0; i<qtd; i++){
        const letra = document.getElementById('letra'+i);
        const deslocamento = Date.now() / 2000 +  0.3 * i * Math.PI / qtd;
        const x = Math.sin(deslocamento) * c1 + c1;
        letra.style.left=x + 'px';
        letra.style.top = c2 +'px';
    }
}
plotarMensagem();
setInterval(movimentar,10);