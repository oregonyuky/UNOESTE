const express = require('express')
const exphbs = require('express-handlebars')
const porta = 3000
//inicializar express na constante app
const app = express()

//definir em app engine do handlebars
app.engine('handlebars', exphbs.engine())

//setar a view
app.set('view engine', 'handlebars')

//renderizar a view
app.get('/', (req, resp)=>{

    //criar uma variável usuario com seus respectivos valores
    //se fosse no banco de dados estaria resgatando com um select

    const usuario = {
        nome:"Ana",
        sobrenome:"Silva"
    }

    //enviar outra variavel
    const loja = "Loja Vendas & Vendas"

    //renderizar a view para home
    //no segunda parâmetro de render posso especificar a chave e valor que quero enviar
    resp.render('home', {usuario: usuario, loja})
})

app.listen(porta, ()=>{
    console.log(`App rodadno na porta ${porta}`)
})