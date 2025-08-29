//alert('alert')           
//const nome = prompt('Digite o nome')
//alert('O nome digitado e: ' + nome)
//const confirmarNome = confirm('Este e o seu nome')
//if(confirmarNome){
    //alert('Nome correto')
//}else{
//    alert('Nome errado')
//}

const divjs = document.getElementById('testeDom')
console.log(divjs)

const tituloJs = document.getElementsByClassName('titulo')
console.log(tituloJs)

const nomeJs = document.getElementsByName('nomeTag')
console.log(nomeJs[0])
console.log(nomeJs[0].tagName)
for(i=0;i<nomeJs.size;i++){
    console.log(nomeJs[i])
}

const tagName = document.getElementsByTagName('span')
console.log(tagName)
console.log(tagName[1])

tagName[1].innerHTML = 'Span com elemento alterado utilizando innerHTML'
const elemento = document.querySelector('.classHTML') 
console.log(elemento)

const elementos = document.querySelectorAll('.classHTML')
console.log(elementos[0])
console.log(elementos[1])

const idP = document.getElementById('conteudoP')
console.log(idP)
//copia idP para const conteudoPHTML
const conteudoPHTML = idP.innerHTML
console.log(conteudoPHTML)
//alterar conteudo utiliznado innerHTML
const conteudoAlterado = 'alterar conteudo de p'
idP.innerHTML = conteudoAlterado
idP.innerHTML = 'alterar 2a vez'

const idCL = document.getElementById('textP')
idCL.classList.add('blue')

//remover a class -> remove
idCL.classList.remove('textoPclass')
console.log(idCL[0])

//criar elemento com javascript -> createElement
const div = document.createElement('div')
div.innerHTML = 'criando div com JS'
console.log(div)

//adicionar e remover elementos -> appendChild
const conteudoDiv = document.getElementById('idDiv')
const logoHTML = document.createElement('img')
logoHTML.src = './logo.png'
conteudoDiv.appendChild(logoHTML)
const titulo = document.createElement('h1')
titulo.innerHTML = 'Logo do JS'
conteudoDiv.appendChild(titulo)

//pegar o atributo -> getAttribute
const logo = document.getElementById('logo')
const atributo = logo.getAttribute('alt')
console.log(atributo)

//setAttribute
logo.setAttribute('width', '300')
function saudacao(){
    alert('alerta botao 1')
}
function mostrarcaixa(){
    const caixa = document.getElementById('caixa')
    caixa.style.display = 'block'
}
function trocarTexto(){
    const texto = document.querySelector('p')
    texto.innerHTML = 'texto alterado'
}
function carregarPagina(){
    alert('Pagina carregada')
}
function enviar(){ 
    const soma = document.getElementById('soma')
    if(parseInt(soma.value)==9)
        alert('acertou')
    else
        alert('errou')
}
function enviar(){ 
    const sub = document.getElementById('sub')
    if(parseInt(sub.value)==5)
        alert('acertou')
    else
        alert('errou')
}
const form = document.getElementById('formulario')
form.addEventListener('submit', subtrair)