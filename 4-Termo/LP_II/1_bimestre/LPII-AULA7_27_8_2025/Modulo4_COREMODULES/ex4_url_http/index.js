const http = require('http')
const  url = require('url')

const port = 3000
const servidor = http.createServer((req, resp) =>{
    //saber a url que está chegando
    //criar const para receber a url decomposta
    const urlInfo = url.parse(req.url, true)
    //burcar o parametro nome na url
    const nome = urlInfo.query.nome

    resp.statusCode = 200
    resp.setHeader('Contenty-Type', 'text/html')

    if(!nome){
        resp.end('<h1>Qual e o seu nome?</h1><form method="GET"><input type="text" name="nome"/><input type="submit" value="Enviar"></form>')
    }else{
        resp.end(`<h1>Seja bem vindo ${nome}</h1>`)
    }
})

servidor.listen(port,()=>{
    console.log(`Servidor na porta ${port}`)
})