const express = require('express')
const rota = express.Router()
const ConsultaController = require('../controller/ConsultaController')
const middleware = require('../middlewares/ConsultaValida')
const ConsultaValida = middleware.ConsultaValida
rota.post('/', ConsultaValida, ConsultaController.criar)
module.exports = rota
