const ConsultaModel = require('../model/ConsultaModel')
const { isPast } = require('date-fns')
const ConsultaValida = async (req, resp, next) => {
    const tipo = req.body.tipo
    const paciente = req.body.paciente
    const descricao = req.body.descricao
    const data = new Date(req.body.data)
    if(!tipo)
        return resp.status(400).json({erro: 'O tipo da consulta é obrigatório'})
    if(!paciente)
        return resp.status(400).json({erro: 'O nome do paciente é obrigatório'})
    if(!descricao)
        return resp.status(400).json({erro: 'A descrição da consulta é obrigatória'})
    if(isPast(new Date(data)))
        return resp.status(400).json({erro: 'A data da consulta é obrigatória e não pode ser no passado'})
    let existe
    existe = await ConsultaModel.findOne({'data': {$eq: new Date(data)}})
    if(existe)
        return resp.status(400).json({erro: 'Já existe uma consulta agendada para essa data e horário'})
    next()
}
module.exports = ConsultaValida 