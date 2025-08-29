const http = require('http')
const url = require('url')
const fs = require('fs')
const port = 3000

const servidor = http.createServer((req,resp)=>{
    const UrlInfo = url.parse(req.url, true)
    //quero saber qual o filename com base na minh aurl acessada
    // /.... sub(1) pegar o que tem depois do /
    const fileName = UrlInfo.pathname.substring(1)
    //saber se existe o arquivo html, pois so iremos renereizar o html caso exista
    if(fileName.includes('html')){
        //usurario somente acessou a pagina, nao tem nada no meu form
        if(fs.existsSync(fileName)){
            fs.readFile(fileName, function(err, data){
                resp.writeHead(200, {'content-type': 'text/html'})
                resp.write(data)
                return resp.end()
            })
        }
    }else{
        //pagina 404 - notif. pagina nao existe e retornar para a home
        //já tenho um form preenchido pelo usuario
        //escrever em um arquivo quando receber o valor de cor
        fs.readFile("404.html", function(err, data){
            resp.writeHead(404, {'content-type': 'text/html'})
            resp.write(data)
            return resp.end()
        })
    }
})

servidor.listen(port,()=>{
    console.log(`Porta: ${port}`)
})