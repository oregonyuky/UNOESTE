function semiCirculo(a,b,r,x){
    //retornar a coordenada y da plotagem 
    //no plano carteziano
    //centro círculo (a,b)
    //x é a coordenada da reta x
    //raio é o tamanho do circulo
    return b + Math.sqrt(Math.pow(r,2) - Math.pow(x-a,2));
}

const a = 100;
const b = 100;
const raio = 100;
for (let x = 0; x<=(2*a); x++){
    const ponto = document.createElement('p');
    ponto.innerHTML = '.';
    ponto.style.position='absolute';
    ponto.style.top = semiCirculo(a,b,raio,x) + 'px';
    ponto.style.left= x + 'px';
    document.body.appendChild(ponto);
}