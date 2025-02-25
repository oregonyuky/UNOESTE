function exibirMensagem(){
    alert(mensagem);
}
function confirmacao(texto){
    return confirm(texto);
}
function result(valor1, valor2, operacao){
    let result;
    switch(operacao){
        case '+':result = valor1 + valor2;break;
        case '-':result = valor1 - valor2;break;
        case '*':result = valor1 * valor2;break;
        case '/':result = valor2 !==0 ? valor1 / valor2 : "Erro: divisaopor zero";break;
        default: return "Operacao invalida";
    }
    return result;
}
const valor1 = parseFloat(prompt("Digite o valor1:"));
const valor2 = parseFloat(prompt("Digite o valor2:"));
const operacao = prompt("Digite a operacao (+, -, *, /):");
if(confirmacao("Confirmar a decisao?")){
    const resultado = result(valor1, valor2, operacao);
    exibirMensagem("Resultado da operacao eh: " + resultado);
}
else{
    exibirMensagem("Faca de novo");
}
