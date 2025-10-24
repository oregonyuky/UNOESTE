const express = require('express')
const app = express()
const port = 3000
const path = require('path')
const basePath = path.join(__dirname, 'templates_html')

//importar o router rota usuário
const rotaUsuario = require('./usuarios')

//ler body
app.use(
    express.urlencoded({
        extended: true,
    }),
)
app.use(express.json())

app.use('/usuarios',rotaUsuario)

app.get('/', (req, resp) =>{
    resp.sendFile(`${basePath}/index.html`)
})

app.listen(port, ()=>{
    console.log(`App rodando na porta ${port}`)
})
