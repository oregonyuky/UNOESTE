const express = require('express')

//variavel app para executar o express
const app = express()
const port = 3000

const path = require('path')

//estamos na pasta ex5_renderHTML queremos partir para 
//a pasta templates_html
//join do _dirname para templates
const basePath = path.join(__dirname, 'templates_html')

app.get('/', (req, resp) =>{
    resp.sendFile(`${basePath}/index.html`)
})

app.listen(port, ()=>{
    console.log(`App rodando na porta ${port}`)
})
