const dataatual = new Date();
hora = dataAtual.getHours();
if(hora >= 0 && hora <= 12){
    document.write("<img src='./img/bomdia.png'");
}
else if(hora > 12 && hora < 18){
    document.write("<img src='./img/boatarde.png'");
}
else{
    document.write("<img src='./img/boanoite.png'");
}
