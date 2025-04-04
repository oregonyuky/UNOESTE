const largura = 121;
const altura = 127;
var posX = 0;
var posY = 0;
const passo = 10;
var frame = 0;
const limiteMaxX = window.innerWidth;
const limiteMaxY = window.innerHeight;
const limitMinX = 0;
const limitMinY = 0;
var vida = 3;
var pontuacao = 0;

var qtdImagensSprite = 9;
const tela = document.getElementById("tela");
const infoVida = document.getElementById("vida");
const infoPontuacao = document.getElementById("pontuacao");
const gameArea = document.getElementById("gameArea");

function prepararTela() {
    tela.style.position = "absolute";
    tela.style.width = largura + "px";
    tela.style.height = altura + "px";
    tela.style.top = posY + "px";
    tela.style.left = posX + "px";
    tela.style.backgroundImage = "url('./img/tras_d.png')";
    atualizarHUD();
    gerarInimigos();
}

function atualizarHUD() {
    infoVida.innerText = "Vida: " + vida;
    infoPontuacao.innerText = "Pontuação: " + pontuacao;
}

document.onkeydown = animar;

document.addEventListener("keydown", function(evento) {
    if (evento.key === "Space") {
        atacar();
    }
});

function animar(evento) {
    if (evento.key === "ArrowRight") {
        qtdImagensSprite = 9;
        if ((posX + largura) < limiteMaxX) {
            posX += passo;
            tela.style.backgroundImage = "url('./img/direita.png')";
            tela.style.left = posX + "px";
            frame += 1;
        }
    }
    if (evento.key === "ArrowLeft") {
        qtdImagensSprite = 9;
        if (posX > limitMinX) {
            posX -= passo;
            tela.style.backgroundImage = "url('./img/esquerda.png')";
            tela.style.left = posX + "px";
            frame += 1;
        }
    }
    if (evento.key === "ArrowUp") {
        qtdImagensSprite = 7;
        if (posY > limitMinY) {
            posY -= passo;
            tela.style.backgroundImage = "url('./img/frente_d.png')";
            tela.style.top = posY + "px";
            frame += 1;
        }
    }
    if (evento.key === "ArrowDown") {
        qtdImagensSprite = 7;
        if ((posY + altura) < limiteMaxY) {
            posY += passo;
            tela.style.backgroundImage = "url('./img/tras_d.png')";
            tela.style.top = posY + "px";
            frame += 1;
        }
    }
    verificarColisoes();
}

function verificarColisoes() {
    let inimigos = document.getElementsByClassName("inimigo");
    let trofeus = document.getElementsByClassName("trofeu");

    for (let inimigo of inimigos) {
        if (colisao(tela, inimigo)) {
            vida -= 1;
            atualizarHUD();
            if (vida <= 0) {
                alert("Game Over!");
                reiniciarJogo();
            }
        }
    }
    for (let trofeu of trofeus) {
        if (colisao(tela, trofeu)) {
            pontuacao += 10;
            trofeu.remove();
            atualizarHUD();
        }
    }
}

function atacar() {
    let inimigos = document.getElementsByClassName("inimigo");
    for (let inimigo of inimigos) {
        if (colisao(tela, inimigo)) {
            pontuacao += 20;
            inimigo.remove();
            atualizarHUD();
        }
    }
}

function colisao(obj1, obj2) {
    let r1 = obj1.getBoundingClientRect();
    let r2 = obj2.getBoundingClientRect();
    return !(r1.right < r2.left || r1.left > r2.right || r1.bottom < r2.top || r1.top > r2.bottom);
}

function reiniciarJogo() {
    vida = 3;
    pontuacao = 0;
    posX = 0;
    posY = 0;
    prepararTela();
}

function gerarInimigos() {
    for (let i = 0; i < 5; i++) { // Gera 5 inimigos aleatórios
        let inimigo = document.createElement("div");
        inimigo.classList.add("inimigo");
        inimigo.style.position = "absolute";
        inimigo.style.width = "50px";
        inimigo.style.height = "50px";
        inimigo.style.backgroundImage = "url('./img/inimigo.png')";
        inimigo.style.backgroundSize = "cover";
        inimigo.style.left = Math.random() * (limiteMaxX - 50) + "px";
        inimigo.style.top = Math.random() * (limiteMaxY - 50) + "px";
        gameArea.appendChild(inimigo);
    }
}

prepararTela();

