const express = require('express')
const rota = express.Router()
const path = require('path')
const basePath = path.join(__dirname, '../templates_html')

rota.get('/adicionar', (req, resp)=>{
    resp.sendFile(`${basePath}/usuarioForm.html`)
})
rota.post('/salvar',(req, resp)=>{
    //ler o objeto por requisição.body
    console.log(req.body)
    const nome = req.body.nome
    const idade = req.body.idade
    console.log(`O usuário ${nome} tem ${idade} anos`)
    resp.sendFile(`${basePath}/usuarioForm.html`)
  
})

rota.get('/:id', (req, resp) =>{
    const id = req.params.id
    console.log(`Usuário com o id: ${id}`)
    resp.sendFile(`${basePath}/usuarios.html`)
})

module.exports = rota