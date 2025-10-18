const express = require('express')

//chamar a rota do express
const rota = express.Router()

//chamar o controllers
const ProdutosController = require('../controllers/ProdutosController')

//rota passando o id
rota.get("/:id", ProdutosController.recuperarProduto)

//rota para deletar produto
rota.post("/deletar/:id", ProdutosController.deletarProduto)

rota.get("/editar/:id", ProdutosController.editarProtudo)

rota.post('/salvar', ProdutosController.salvarProduto)

//criar uma rota para iniciar 
rota.get('/', ProdutosController.exibirProdutos)
//criar uma rota para criar produtos
rota.get('/criar', ProdutosController.criarProduto)

rota.post('/criar', ProdutosController.criarProdutoPost)


//exportar a rota
module.exports = rota