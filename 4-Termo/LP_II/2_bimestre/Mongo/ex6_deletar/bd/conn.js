//chamar o MongoClient (objeto do Mongodb)
const {MongoClient} = require('mongodb')

//criar uma uri , protocolo do mongodb + ip do servidor
// por padrão a porta do mongo é 27017
//criar o banco com onomo automaticamente: testemongodb2
const uri = "mongodb://localhost:27017/bdprodutos"

//variavel client passando a uri para a requisição
const client = new MongoClient(uri)

//função assincrona (run) com o obj de conectar o banco
async function run() {
    try{
        await client.connect()
        console.log("Conectando ao MongoDB")
    }catch(err){
        console.log(err)
    }
}

run()

//diponibilizar o client na exportação
module.exports = client