const express = require('express')
const exphbs = require('express-handlebars')
const porta = 3000
const app = express()
app.engine('handlebars', exphbs.engine())
app.set('view engine', 'handlebars')
app.get('/relatorio', (req, resp)=>{
    const lista = ["item 1", "item 2", "item 3"]
    resp.render('relatorio', {lista})
})
app.get('/', (req, resp)=>{
    const usuario = {
        nome: "Ana",
        sobrenome: "Silva"
    }
    const aprovado = true
    const loja = "Loja Vendas & Vendas"
    const auth = false
    resp.render('home', {usuario: usuario, loja, auth, aprovado})
})
app.listen(porta, ()=>{
    console.log(`App rodando na porta http://localhost:${porta}`)
})
