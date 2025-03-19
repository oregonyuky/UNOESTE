//Entrega do projeto Calculadora - Felipe Akio Nishimura - 102418462 - 3_termo

//Manipulação da Árvore DOM e Controle de Eventos
const button0 = document.getElementById('button0');
const button1 = document.getElementById('button1');
const button2 = document.getElementById('button2');
const button3 = document.getElementById('button3');
const button4 = document.getElementById('button4');
const button5 = document.getElementById('button5');
const button6 = document.getElementById('button6');
const button7 = document.getElementById('button7');
const button8 = document.getElementById('button8');
const button9 = document.getElementById('button9');
const buttonSoma = document.getElementById('buttonSoma');
const buttonSub = document.getElementById('buttonSub');
const buttonMult = document.getElementById('buttonMult');
const buttonDiv = document.getElementById('buttonDiv');
const buttonResul = document.getElementById('buttonResul');
const buttonLimpar = document.getElementById('buttonLimpar');
const inputNum = document.getElementById('num');
let num1 = null;
let num2 = null;
let oper = "";
let novoNumero = false;
function clicarNumero(valor){
    if (inputNum.value === "0" || novoNumero){
        inputNum.value = valor;
        novoNumero = false;
    }
    else{
        inputNum.value += valor;
    }
}
[button0, button1, button2, button3, button4, button5, button6, button7, button8, button9].forEach((button, index) => {
    button.addEventListener('click', () => clicarNumero(index));
});
function definirOperacao(op){
    if(num1 === null){
        num1 = parseFloat(inputNum.value);
    }
    else if(!novoNumero){
        calcularResultado();
    }
    oper = op;
    novoNumero = true;
}
function calcularResultado(){
    if (num1 !== null && oper !== "" && !novoNumero){
        num2 = parseFloat(inputNum.value);
        switch (oper) {
            case "+":
                num1 += num2;
                break;
            case "-":
                num1 -= num2;
                break;
            case "*":
                num1 *= num2;
                break;
            case "/":
                num1 = num2 !== 0 ? num1 / num2 : "Erro";
                break;
        }
        inputNum.value = num1;
        oper = "";
        novoNumero = true;
    }
}
//Realização de Operações
buttonSoma.addEventListener('click', () => definirOperacao('+'));
buttonSub.addEventListener('click', () => definirOperacao('-'));
buttonMult.addEventListener('click', () => definirOperacao('*'));
buttonDiv.addEventListener('click', () => definirOperacao('/'));
buttonResul.addEventListener('click', calcularResultado);
//Limpeza do Visor
buttonLimpar.addEventListener('click', function(){
    inputNum.value = "0";
    num1 = null;
    num2 = null;
    oper = "";
    novoNumero = false;
});

