//importar o react que traz todos os recursos dele
import React from 'react';
import Header from '../../components/Header';
import * as Styl from './styles'
import Footer from '../../components/Footer';
import FiltrarConsulta from '../../components/ConsultarFiltrar';
import ConsultaCartao from '../../components/ConsultaCartao';
import api from '../../services/api'
import { useState, useEffect } from 'react';
function Home() {
  const [consulta, atualizaConsulta] = useState([]);
  async function carregarConsulta(){
    await api.get(`consulta/${filtroConsulta}`)
    .then(resposta => {
      atualizaConsulta(resposta.data);
      console.log(resposta.data);
    })
  }
  useEffect(()=>{
    carregarConsulta();
  }, {filtroConsulta})
  const [filtroConsulta, atualizarFiltroAtivo] = useState('hoje')
  return  (
    <Styl.Container>
      <Header/>
        <Styl.AreaFiltro>
            <button type='button' onClick={()=>atualizarFiltroAtivo("todos")}>
              <FiltrarConsulta titulo="Todas" ativo={filtroConsulta=="todas"}/>
            </button>
            <button type='button' onClick={()=>atualizarFiltroAtivo("hoje")}>
              <FiltrarConsulta titulo="Hoje" ativo={filtroConsulta=="hoje"}/>
            </button>
            <button type='button' onClick={()=>atualizarFiltroAtivo("semana")}>
              <FiltrarConsulta titulo="Semana" ativo={filtroConsulta=="semana"}/>
            </button>
            <button type='button' onClick={()=>atualizarFiltroAtivo("mes")}>
              <FiltrarConsulta titulo="Mes" ativo={filtroConsulta=="mes"}/>
            </button>
            <button type='button' onClick={()=>atualizarFiltroAtivo("ano")}>
              <FiltrarConsulta titulo="Ano" ativo={filtroConsulta=="ano"}/>
            </button>
            <FiltrarConsulta/>
            <FiltrarConsulta/>
            <FiltrarConsulta/>
            <FiltrarConsulta/>
            <FiltrarConsulta/>
        </Styl.AreaFiltro>
        <Styl.Titulo>
          <h1>Consulta</h1>
        </Styl.Titulo>
        <Styl.Cartao>
          <ConsultaCartao/>
          <ConsultaCartao/>
          <ConsultaCartao/>
          <ConsultaCartao/>
        </Styl.Cartao>
      <Footer/>
    </Styl.Container>
)
}
//exportar a função para quando o arquivo for 
// convocado em algum lugar
//eu export tudo que foi definido na função
export default Home;
