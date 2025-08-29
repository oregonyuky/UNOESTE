const http = require('http')
const port = 3000
const servidor = http.createServer((requisicao, resposta)=>{
    //enviar resposta
    resposta.write('texto http')
    //finalizar a resposta
    resposta.end()
})
servidor.listen(port, ()=>{
    console.log(`Servidor rodando na porta: ${port}`)
})