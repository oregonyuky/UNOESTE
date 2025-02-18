var a = 10;
var b = 20;
document.write("<span>Variavel A: </span>", a);
document.write("<span><br>Variavel 8: </span>", b);
a ^= b;
b ^= a^b;
a ^= b;
document.write("<span><br><br>TROCANDO VARIAVEIS...<br></span>");
document.write("<span><br>Variavel A: </span>");
document.write("<span><br>Variavel B: </span>");

document.write("<span><br>MEMORIA E MASCARA<br></span>");

var mem = 145;
var masJog = 0x0F;
var jog = mem & masJog;
document.write("<span><br>O jogador selecionado e: </span>");

var mascFor = 0xF0;
var forJog = (mem & mascFor) >> 4;
document.write("");
