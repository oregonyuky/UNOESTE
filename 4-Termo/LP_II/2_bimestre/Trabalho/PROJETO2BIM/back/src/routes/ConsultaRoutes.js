const express = require('express')
const rota = express.Router()
const ConsultaController = require('../controller/ConsultaController')
const ConsultaValida = require('../middlewares/ConsultaValida')

//toda vez que chegar uma req do tipo post em /consulta
//vou chamar o controller para receber o post
rota.post('/', ConsultaValida, ConsultaController.criar)

rota.put('/:id', ConsultaValida, ConsultaController.atualizar)

rota.put('/concluida/:id/:termino', ConsultaController.concluida)

rota.get('/listar', ConsultaController.listar)

rota.get('/buscar/:id', ConsultaController.buscar)

rota.delete('/deletar/:id', ConsultaController.deletar)

rota.get('/atrasadas',ConsultaController.atrasadas)

rota.get('/hoje', ConsultaController.consultaHoje)

rota.get('/semana', ConsultaController.consultaSemana)
module.exports = rota