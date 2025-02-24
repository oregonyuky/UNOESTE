function  interacao(){
    alert("Seja bem-vindo a nossa pagina");
}
function interacao2(){
    alert("ola, o que vc deseja");
    funcao();
}
function iniciarAtendimento(texto, funcao){
    funcao(interacao2);
    alert("Bom dia! Como posso ajudar");
    alert(texto);
}
iniciarAtendimento("Atendimento, finalizar", interacao);
