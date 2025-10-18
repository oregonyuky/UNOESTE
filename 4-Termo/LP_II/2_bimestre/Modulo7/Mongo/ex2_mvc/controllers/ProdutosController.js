//iniciar a classe
const Produtos = require('../models/Produtos')

//o modulo que foi exportado a classe ProdutosController
module.exports = class ProdutosController{
    static exibirProdutos(req, resp){
        //renderizar uma view para todos os produtos
        resp.render('produtos/todos')
    }
}