const largura = 40;
const altura = 111;
var posX = 0;
var posY = 0;
const passo = 10;
var frame = 0;
const limiteMaxX = window.innerWidth;
const limiteMaxY = window.innerHeight;
const limitMinX = 0;
const limitMinY = 0;


const qtdImagensSprite = 4;

const tela = document.getElementById("tela");

function prepararTela() {
    tela.style.position = "absolute";
    tela.style.width = largura + "px";
    tela.style.height = altura + "px";
    tela.style.top = posY;
    tela.style.left = posX;
    tela.style.backgroundImage = "url('./img/direita.png')";
}

document.onkeydown = animar;

function animar(evento) {
    if (evento.key === "ArrowRight") {
        if ((posX - largura) < limiteMaxX) {
            posX += passo;
            tela.style.backgroundImage = "url('./img/direita.png')";
            tela.style.backgroundPosition = ((frame % qtdImagensSprite) * largura) + "px";
            tela.style.left = posX + "px";
            frame += 1;
        }
    }
    if (evento.key === "ArrowLeft") {
        if ((posX - largura) > 0) {
            posX -= passo;
            tela.style.backgroundImage = "url('./img/esquerda.png')";
            tela.style.backgroundPosition = ((frame % qtdImagensSprite) * largura) + "px";
            tela.style.left = posX + "px";
            frame += 1;
        }
    }
    if (evento.key === "ArrowUp") {
        if (posY > limitMinY) {
            posY -= passo;
            tela.style.backgroundImage = "url('./img/tras.png')";
            tela.style.backgroundPosition = ((frame % qtdImagensSprite) * largura) + "px" ;
            tela.style.top = posY + "px";
            frame += 1;
        }
    }
    if (evento.key === "ArrowDown") {
        if (posY + altura < limiteMaxY) {
            posY += passo;
            tela.style.backgroundImage = "url('./img/frente.png')";
            tela.style.backgroundPosition = ((frame % qtdImagensSprite) * largura) + "px";
            tela.style.top = posY + "px";
            frame += 1;
        }
    }
}


prepararTela();
animar();

