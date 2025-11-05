//iniciar a classe
const Produtos = require('../models/Produtos')

//o modulo que foi exportado a classe ProdutosController
module.exports = class ProdutosController{
    static exibirProdutos(req, resp){
        //renderizar uma view para todos os produtos
        resp.render('produtos/todos')
    }

    //renderizar a view de criacao
    static criarProduto(req, resp){
        resp.render('produtos/criar')
    }

    //post para todas as req do body
    static criarProdutoPost(req, resp){
        const nome = req.body.nome
        const preco = req.body.preco
        const descricao = req.body.descricao

        //instanciar o produto pegando todos os dados 
        const produto =  new Produtos(nome, preco, descricao)

        //salvar no banco
        produto.salvar()

        //redirecionar para a pasta produtos
        resp.redirect('/produtos')

    }
}