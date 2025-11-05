const express = require('express')
const app = express()
const port = 3000
const path = require('path')
const basePath = path.join(__dirname, 'templates_html')
//ler body
app.use(
    express.urlencoded({
        extended: true,
    }),
)
app.get('/usuarios/adicionar', (req, resp)=>{
    resp.sendFile(`${basePath}/usuarioForm.html`)
})
app.post('/usuarios/salvar',(req, resp)=>{
    //ler o objeto por requisição.body
    console.log(req.body)
    const nome = req.body.nome
    const idade = req.body.idade
    console.log(`O usuário ${nome} tem ${idade} anos`)
    resp.sendFile(`${basePath}/usuarioForm.html`)
  
})

app.get('/usuarios/:id', (req, resp) =>{
    const id = req.params.id
    console.log(`Usuário com o id: ${id}`)
    resp.sendFile(`${basePath}/usuarios.html`)
})

app.get('/', (req, resp) =>{
    resp.sendFile(`${basePath}/index.html`)
})

app.listen(port, ()=>{
    console.log(`App rodando na porta ${port}`)
})
