//chamar o express
const express = require('express')
//handlebars
const exphs = require('express-handlebars')
// app express
const app = express()

//conexao com o banco mongo
const conn = require('./bd/conn')

//configurar a handlebars como eng do express
app.engine('handlebars', exphs.engine())

//configurar a view
app.set('view engine', 'handlebars')

//criar a estrutura para ler o body
app.use(
    express.urlencoded({
        extended: true
    })
)

app.use(express.json())

//iniciar o express na porta 3000
app.listen(3000)