
const button0 = document.getElementById('button0');
const button1 = document.getElementById('button1');
const button2= document.getElementById('button2');
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


var oper;
var num=0;
var num1;
var num2;
var result;
var numTemp;
function mostrarNumero(){
    document.getElementById("n").innerHTML =  num;
    document.getElementById("num1").value =  num1;
    document.getElementById("num2").value =  num2;
    document.getElementById("result").value = "resul= " + result;
}

document.onmousemove = mostrarNumero;

button0.addEventListener('click', function(){
    numTemp = document.getElementById('num').value;
    document.getElementById('num').value = (numTemp*10) + 0;
    num = (numTemp*10)+0;
});
button1.addEventListener('click', function(){
    numTemp = document.getElementById('num').value;
    document.getElementById('num').value = (numTemp*10) + 1;
    num = (numTemp*10)+1;
});
button2.addEventListener('click', function(){
    numTemp = document.getElementById('num').value;
    document.getElementById('num').value = (numTemp*10) + 2;
    num = (numTemp*10)+2;
});
button3.addEventListener('click', function(){
    numTemp = document.getElementById('num').value;
    document.getElementById('num').value = (numTemp*10) + 3;
    num = (numTemp*10)+3;
});
button4.addEventListener('click', function(){
    numTemp = document.getElementById('num').value;
    document.getElementById('num').value = (numTemp*10) + 4;
    num = (numTemp*10)+4;
});
button5.addEventListener('click', function(){
    numTemp = document.getElementById('num').value;
    document.getElementById('num').value = (numTemp*10) + 5;
    num = (numTemp*10)+5;
});
button6.addEventListener('click', function(){
    numTemp = document.getElementById('num').value;
    document.getElementById('num').value = (numTemp*10) + 6;
    num = (numTempo*10)+6;
});
button7.addEventListener('click', function(){
    numTemp = document.getElementById('num').value;
    document.getElementById('num').value = (numTemp*10) + 7;
    num = (numTemp*10)+7;
});
button8.addEventListener('click', function(){
    numTemp = document.getElementById('num').value;
    document.getElementById('num').value = (numTemp*10) + 8;
    num = (numTemp*10)+8;
});
button9.addEventListener('click', function(){
    numTemp = document.getElementById('num').value;
    document.getElementById('num').value = (numTemp*10) + 9;
    num = (numtemp*10)+9;
});

buttonSoma.addEventListener('click', function(){
    numTemp = parseInt(document.getElementById('num').value); 
    num1 = numTemp; 
    document.getElementById('num1').innerHTML = "num1: " + num1; 
    document.getElementById('num').value = 0; 
    result += num1;
    num=result;
});
buttonSub.addEventListener('click', function(){
    result -= num;
});
buttonMult.addEventListener('click', function(){
    result *= num;
});
buttomDiv.addEvendListener('clock', function(){
    result /= num;
});


