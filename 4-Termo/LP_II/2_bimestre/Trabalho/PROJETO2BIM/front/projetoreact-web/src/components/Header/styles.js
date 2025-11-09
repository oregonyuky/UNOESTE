import styled from 'styled-components'

export const Container = styled.div`
    width: 100%;
    height: 70px;
    background-color: #C0C0C0;
    /*barra inferior do cabeçalho*/
    border-bottom: 3px solid #22B14C;
    /*componentes em forma de caixa*/
    display: flex;
`
export const Esq = styled.div`
    width: 50%;
    height: 70px;
    display: flex;
    padding-left: 5px;
    img{
        width:200px;
        height: 80px;
    }

`
export const Dir = styled.div`
    width: 50%;
    height: 70px;   
    
    /*centralizar por caixa*/
    display: flex;
    align-items: center;
    /*começar do final da caixa - canto direito*/
    justify-content: flex-end;

    a{
        /*colocar icone com a cor branca*/
        color: #FFF;
        /*deixar em negrito*/
        font-weight: bold;
        /*remocer underline*/
        text-decoration: none;
        /*margin*/
        margin: 0 10px;

        /*quando passar o mouse no escrito ele fica verde*/
        &:hover{
            color: #22B14C;
        }
    }

    #notificacao{   
        img{
            width: 25px;
            height: 25px;
        
        }
        span{
            background-color: #FFF;
            color: #22B14C;
            padding: 3px 7px;
            border-radius: 50%;
            position: relative;
            top: -20px;
            right: 10px;
        
        }
        /*quando passsar o mouse quero que o sino fique opaco*/
        &:hover{
            opacity: 0.5;
        }
    }
    .divisor::after{
        content: "|";
        /*margin em cima 0 dos lados 10*/
        magins: 0 10;
        color: #FFF;
    }

`