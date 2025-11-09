//importar o react que traz todos os recursos dele
import React from 'react';
import Header from '../../components/Header';
import * as Styl from './styles'

function Home() {
  return  (
    <Styl.Container>
      <Header/>
    </Styl.Container>
)
}
//exportar a função para quando o arquivo for 
// convocado em algum lugar
//eu export tudo que foi definido na função
export default Home;
