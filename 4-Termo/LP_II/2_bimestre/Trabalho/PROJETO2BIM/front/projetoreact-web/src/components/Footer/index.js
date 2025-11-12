//importar o react que traz todos os recursos dele
import React from 'react';
import * as Styl from './styles'

function Footer() {
  return (
    <Styl.Container>
        <span>Consulta - 2025</span>
    </Styl.Container>
  );
}
//exportar a função para quando o arquivo for 
// convocado em algum lugar
//eu export tudo que foi definido na função
export default Footer;
