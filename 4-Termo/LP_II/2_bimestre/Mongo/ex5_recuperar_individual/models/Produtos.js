//chamar a conexão
const conn = require('../bd/conn')

//preciso transformar a string em objetoId

const { ObjectId } = require('mongodb')

//class js
class Produto{
    //criar objetos com as propriedades iniciais para cadastrar o produto
    constructor(nome, preco, descricao, imagem){
        //associar  a propriedade à instancia do obj
        this.nome = nome
        this.preco = preco
        this.descricao = descricao
        this.imagem = imagem
    }


    //insert
    salvar(){
   
        const produto = conn.db().collection('produtos').insertOne({
            nome: this.nome,
            preco: this.preco,
            descricao: this.descricao,
            imagem: this.imagem,
        })
        return produto
    }

    //implementar o find
    static recuperarProdutos(){
        const produtos = conn.db().collection('produtos').find().toArray()
        return produtos
    }

    //implementar o getProdutoByID
    //será async, pois ele deve esperar os produtos chegarem para trabalhar na view
    static async getProdutoByID(id){
        const produto = conn.db().collection('produtos').findOne({_id:new ObjectId(id)})
        console.log('BANCO')
        console.log(produto)
        return produto
    }

}
module.exports = Produto