import styled from 'styled-components'

//exportar uma constante container que vai receber 
//o styled como uma div

export const Container = styled.div`
    width: 100%;
    padding: 24px;
    box-sizing: border-box;
    display: flex;
    flex-direction: column;
    gap: 16px;
`
export const AreaFiltro = styled.div`
    width:100%;
    display:flex;
    flex-wrap: wrap;
    justify-content: space-around;
    margin-top: 30px;
    button{
        backgound: none;
        border:none;
    }
`

export const Cartao = styled.div`
    width: 100%;
    display: flex;
    flex-wrap: wrap;
    justify-content: center;
`
export const Titulo = styled.div`
    width: 100%;
    border-bottom: 1px solid #22B14C;
    display: flex;
    margin: 20px;
    h3{
        color: #22B14C;
        position: relative;
        top: 30px;
        background: #FFF;
        padding: 0 20px;
    }
`