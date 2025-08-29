const http = require('http')
const fs = require('fs')

const port = 3000

const servidor=http.createServer((req,resp)=>{
    //renderizar html via fs
    //readFile para ler o arquivo mensagem.html  
    //criar funcao responsável par apresentar o erro
    fs.readFile('mensagem.html',function(err,data){
        resp.writeHead(200,{'content-type': 'text/html'})
        resp.write(data)
        return resp.end()
    })
})

servidor.listen(port,()=>{
    console.log(`Porta: ${port}`)
})