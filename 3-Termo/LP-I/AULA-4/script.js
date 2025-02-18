var memoria = 23;
var mascaraJogador = 0x0F;
var jogador = memoria & mascaraJogador;
document.write("O jogador selecionado e: " + jogador);
document.write("<br/>");

var mascaraForca = 0xF0;
var forcaJogador = (memoria & mascarForca) >> 4;

document.write("<br><br>");
document.write("A forca do jogadro e: " + forcaJogador);
