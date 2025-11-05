const express = require('express')

//chamar a rota do express
const rota = express.Router()

//chamar o controllers
const ProdutosController = require('../controllers/ProdutosController')

//criar uma rota para iniciar 
rota.get('/', ProdutosController.exibirProdutos)
//criar uma rota para criar produtos
rota.get('/criar', ProdutosController.criarProduto)

rota.post('/criar', ProdutosController.criarProdutoPost)


//exportar a rota
module.exports = rota