function mensagem(texto){
    const entrada = function(){
        return prompt("Qual e o seu nome?");
    }
    alert(texto);
    alert(entrada());
}
mensagem("Ola");
