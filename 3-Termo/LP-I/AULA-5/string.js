function exibirMensagem()
{
    alert(mensagem);
}
function gets(texto)
{
    return input(texto);
}
function confirmacao(texto)
{
    return confirm(texto);
}
exibirMensagem("Bom dia!");
gets("Qual o seu nome?");
const nome = gets("Qual e o seu nome?");
if(confirmacao("Gostaria de pedir alguma coisa?"))
{
    exibirMensagem("Seja bme vindo! " + nome);
    exibirMensagem("Por favor, aguarde que voce sera"):
}
else{
    exibirMensagem("Obrigado pela preferencia!");
}
