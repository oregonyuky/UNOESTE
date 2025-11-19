import styled from 'styled-components'
export const Container = styled.div`
    width: 250px;
    height: 220px;
    display: flex;
    align-items: center;
    justify-content: center;
    border-radius: 10px;
    flex-direction: column;
    margin: 20px;
    box-shadow: -3px 1p 13px -2px rgba(0,0,0,0.73);
    cursor: pointer;
    &:hover{
        opacity: 0.8;
    }
`
export const TopoCartao = styled.div`
    display: flex;
    align-items: center;
    justify-content: center;
    flex-direction: column;
    img{
        width: 100px;
        height: 100px;
    }
`
export const BotaoCartao = styled.div`
    width: 100%;
    diplay: flex;
    justify-content: space-around;
    strong{
        color: #22B14C;
        font-weight: bold;
    }
    span{
        color: #707070;
    }
`