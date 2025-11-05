//iniciar a classe
const Produtos = require('../models/Produtos')

//o modulo que foi exportado a classe ProdutosController
module.exports = class ProdutosController{
    static async exibirProdutos(req, resp){
        //renderizar uma view para todos os produtos
        const produtos = await Produtos.recuperarProdutos()
        console.log(produtos)

        resp.render('produtos/todos', {produtos})
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

        const imagem = req.body.imagem

        //instanciar o produto pegando todos os dados 
        const produto =  new Produtos(nome, preco, descricao, imagem)

        //salvar no banco
        produto.salvar()

        //redirecionar para a pasta produtos
        resp.redirect('/produtos')

    }


    //função para recuperar um produto
    static async recuperarProduto(req, resp){
        //recuperar o id da requisição
        const id = req.params.id

        //recuperar o produto pelo método costumizado passando o id
        const produto = await Produtos.getProdutoByID(id)

        console.log(produto)

        //retornar para a página de produto
        resp.render('produtos/produto',{produto})

    }


    //função para deletar produto
    static async deletarProduto(req, resp){
        //recuperar o id da url
        const id = req.params.id

        //esperar a remoção para garantir que ela foi realizada com sucesso
        await Produtos.deletarProdutoById(id)

        resp.redirect('/produtos')
    }

}