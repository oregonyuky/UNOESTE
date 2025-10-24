//chamar a conexão
const conn = require('../bd/conn')


//class js
class Produto{
    //criar objetos com as propriedades iniciais para cadastrar o produto
    constructor(nome, preco, descricao){
        //associar  a propriedade à instancia do obj
        this.nome = nome
        this.preco = preco
        this.descricao = descricao
    }

    //método para salvar no banco
    //insert
    salvar(){
        //chamar o método passando qual a collection ele vai inserir as informações
        //para inserir é realizada a chamada do método InsertOne 
        //a diferença para um banco relacional(ex: mysql) é que nesse caso seria realiza
        // a criação da query
        //no mongo vamos salvar em um document a collection produtos
        //estamos utilizando p banco nomeado como:bdprodutos
        const produto = conn.db().collection('produtos').insertOne({
            //passar os dados para o método
            nome: this.nome,
            preco: this.preco,
            descricao: this.descricao,
        })
        //retornar o produto para ver se deu certo a inserção
        return produto
    }
}
module.exports = Produto