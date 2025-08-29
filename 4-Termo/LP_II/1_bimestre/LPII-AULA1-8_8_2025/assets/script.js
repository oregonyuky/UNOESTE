
cInput = document.querySelector('#c');
fInput = document.querySelector('#f');
rInput = document.querySelector('#r');
dInput = document.querySelector('#d');

cInput.addEventListener("keyup", ()=>{
    console.log("apertou o campo C")
    console.log(cInput.value)
    converteTemp("c-para-f")
})
fInput.addEventListener("keyup", ()=>{
    console.log("apertou o campo F")
    console.log(fInput.value)
    converteTemp("f-para-c")
})
rInput.addEventListener("keyup", ()=>{
    console.log(rInput.value)
    converteTemp("real-dolar")
})
dInput.addEventListener("keyup", ()=>{
    console.log(dInput.value)
    converteTemp("dolar-real")
})
function converteInt(value){
    IntValue = parseInt(value)
    if(IntValue == NaN){
        Intvalue = 0
    }
    return IntValue
}
function converteTemp(type){
    if(type == "c-para-f"){
        valorC = converteInt(cInput.value)
        resultado = valorC*1.8+32
        resultado = resultado.toFixed(2)
        fInput.value = converteInt(resultado)
    }
    if(type == "f-para-c"){
        valorF = converteInt(fInput.value)
        resultado = (valorF-32)/1.8
        resultado = resultado.toFixed(2)
        cInput.value = converteInt(resultado)
    }
    if(type == "real-dolar"){
        valorC = rInput.value
        resultado = valorC*0.18
        resultado = resultado.toFixed(2)
        rInput.value = resultado
    }
    if(type == "dolar-real"){
        valorF = dInput.value
        resultado = valorF/0.18
        resultado = resultado.toFixed(2)
        dInput.value = resultado
    }
}