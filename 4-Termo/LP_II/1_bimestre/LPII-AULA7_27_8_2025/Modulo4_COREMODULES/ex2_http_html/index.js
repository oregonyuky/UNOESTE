//modulo http
const http = require('http')

//porta 
const port = 3000

//constante para receber servidor
const servidor = http.createServer((req,resp)=>{
    //status - 200 -> requisição bem sucedida
    resp.statusCode = 200
    //alterar conteudo do header (cabeçalho) do html 
    resp.setHeader('Contenty-Type', 'text/html')
    // com o end eu consigo passar os textos em html via js por meio das tags
    resp.end('<h1> testando html</h1>')
})

//escutar a porta com a função callback
servidor.listen(port, ()=>{
    console.log(`Servidor rodando na porta: ${port}`)
})