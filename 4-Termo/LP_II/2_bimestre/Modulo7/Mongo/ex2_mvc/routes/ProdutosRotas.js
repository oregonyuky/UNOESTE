const express = require('express')

//chamar a rota do express
const rota = express.Router()

//chamar o controllers
const ProdutosController = require('../controllers/ProdutosController')

//criar uma rota para iniciar 
rota.get('/', ProdutosController.exibirProdutos)

//exportar a rota
module.exports = rota