const express = require('express')

//chamar a rota do express
const rota = express.Router()

//chamar o controllers
const ProdutosController = require('../controllers/ProdutosController')

//rota passando o id
rota.get('/criar', ProdutosController.criarProduto)

rota.post('/criar', ProdutosController.criarProdutoPost)
rota.post('/salvar', ProdutosController.salvarProduto)
rota.post("/deletar/:id", ProdutosController.deletarProduto)

rota.get("/editar/:id", ProdutosController.editarProtudo)
rota.get('/', ProdutosController.exibirProdutos)
rota.get("/:id", ProdutosController.recuperarProduto)

//rota para deletar produto




//exportar a rota
module.exports = rota