import styled from 'styled-components'
export const Container = styled.div`
    width: 300px;
    height: 100px;
    background-color: ${prop=>prop.ativo == 'true' ? '#22B24C' : '#C0C0C0'};
    display: flex;
    border-radius: 5px;

    flex-direction: column;
    justify-content: space-around;
    cursor: pointer;

    &:hover{
        color: #22B24C  
    }

    img{
        width: 25px;
        height: 25px;
    }

    span{
        color: #FFF;
        fonrt-weight: bold;
        align-self: flex-end;
        font-size: 18px;
    }

`
