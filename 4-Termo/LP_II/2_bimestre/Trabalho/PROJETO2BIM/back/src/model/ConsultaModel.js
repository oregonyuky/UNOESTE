const { model } = require('mongoose')
const mongoose = require('../config/db')
const Schema = mongoose.Schema
const ConsultaSchema = new Schema({
    tipo: {type: Number, required: true},
    paciente:{type: String, required: true},
    descricao:{type: String, required: true},
    data:{type: Date, required: true},
    termino:{type: Boolean, default: false},
    criada: {type: Date, default: Date.now()}
})
module.exports = mongoose.model('Consulta', ConsultaSchema)