//importar o react que traz todos os recursos dele
import React from 'react';
import * as Styl from './styles'
import filtro from '../../assets/filtro.png'

function FiltrarConsulta({titulo, ativo}) {
  return (
    <Styl.Container ativo={ativo}>
        <img src={filtro} alt="Filtro"/>
        <span>{titulo}</span>
    </Styl.Container>
  );
}
//exportar a função para quando o arquivo for 
// convocado em algum lugar
//eu export tudo que foi definido na função
export default FiltrarConsulta;
