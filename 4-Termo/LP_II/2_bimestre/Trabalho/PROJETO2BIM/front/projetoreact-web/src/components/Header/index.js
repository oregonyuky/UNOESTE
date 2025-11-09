//importar o react que traz todos os recursos dele
import React from 'react';
import * as Styl from './styles'
import logo from '../../assets/logo.png'
import sino from '../../assets/sino.png'

function Header() {
  return (
    <Styl.Container>
        <Styl.Esq>
            <img src={logo} alt="Logo"/>
        </Styl.Esq>
        <Styl.Dir>
          <a href='#'>Início</a>
          <span className="divisor"/>
          <a href='#'>Nova consulta</a>
          <span className="divisor"/>
          <a href='#' id="notificacao">
              <img src={sino} alt="Notificação"/>
              <span>5</span>
          </a>

        </Styl.Dir>
    </Styl.Container>
  );
}
//exportar a função para quando o arquivo for 
// convocado em algum lugar
//eu export tudo que foi definido na função
export default Header;
