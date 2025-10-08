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
    //renderizar a view para home
    resp.render('home', {layout: false})
})
app.listen(porta, ()=>{
    console.log(`App rodando na porta http://localhost:${porta}`)
})
