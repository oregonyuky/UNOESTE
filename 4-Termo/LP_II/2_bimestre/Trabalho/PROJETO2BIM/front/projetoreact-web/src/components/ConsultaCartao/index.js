//importar o react que traz todos os recursos dele
import React from 'react';
import * as Styl from './styles'
import iconePadrao from '../../assets/padrao.png'
function ConsultaCartao() {
  return (
    <Styl.Container>
        <Styl.TopoCartao>
            <img src={iconePadrao} alt="Icone consulta padrao"/>
            <h1>Nome paciente</h1>
        </Styl.TopoCartao>
        <Styl.BotaoCartao>
            <strong>12/11/2025</strong>
            <span>12:00</span>
        </Styl.BotaoCartao>
    </Styl.Container>
  );
}
//exportar a função para quando o arquivo for 
// convocado em algum lugar
//eu export tudo que foi definido na função
export default ConsultaCartao;
