const express = require('express')
const exphs = require('express-handlebars')
const app = express()

const conn = require('./bd/conn')

////importar a rota
const ProdutosRotas = require('./routes/ProdutosRotas')

app.engine('handlebars', exphs.engine())
app.set('view engine', 'handlebars')

app.use(
    express.urlencoded({
        extended: true
    })
)

app.use(express.json())

//// definir a chama do arquivo css
app.use(express.static('public'))

//rotas dos produtos
app.use('/produtos', ProdutosRotas)



app.listen(3000)