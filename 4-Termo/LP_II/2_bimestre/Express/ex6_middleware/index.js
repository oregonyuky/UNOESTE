const express = require('express')

//variavel app para executar o express
const app = express()
const port = 3000

const path = require('path')

//estamos na pasta ex5_renderHTML queremos partir para 
//a pasta templates_html
//join do _dirname para templates
const basePath = path.join(__dirname, 'templates_html')

//variavel para checkar a aplicação
const checkAuth = function(req, resp, next){
    //alterar status para tru
    req.authStatus = false
    if(req.authStatus){
        console.log('Está logado')
        //deixa o usuário ir para a próxima etapa
        next()
    }else{
        console.log('Não está logado, faça o login para continuar')
        next()
    }

}
//toda requisição que for enviada pelo sistema irá ativar o middleware
app.use(checkAuth)

app.get('/', (req, resp) =>{
    resp.sendFile(`${basePath}/index.html`)
})

app.listen(port, ()=>{
    console.log(`App rodando na porta ${port}`)
})
