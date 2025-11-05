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
        // validar id antes de criar ObjectId
        if (!ObjectId.isValid(id)) {
            return null
        }
        const produto = await conn.db().collection('produtos').findOne({_id: new ObjectId(id)})
        return produto
    }
    //metodo para deletar produto do banco
    static async deletarProdutoById(id){
        if (!ObjectId.isValid(id)) return
        await conn.db().collection('produtos').deleteOne({_id: new ObjectId(id)})
        return
    }
    //método para atualizar a salvar os dados alterados
    async salvarProdutoBD(id){
        if (!ObjectId.isValid(id)) return
        const dados = {
            nome: this.nome,
            preco: this.preco,
            descricao: this.descricao,
            imagem: this.imagem
        }
        // garantir retorno/await
        return await conn.db()
            .collection('produtos')
            .updateOne({_id: new ObjectId(id)}, {$set: dados})
    }


}
module.exports = Produto