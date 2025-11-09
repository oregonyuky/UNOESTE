//mongoose
const mongoose = require('../config/db')

//shema
//representação de informações para armazenar os dados no banco
const Schema = mongoose.Schema

//criar o arquivo de configuração
const ConsultaSchema = new Schema({

    tipo: {type: Number, required: true},
    paciente: {type: String, required: true},
    descricao: {type: String, required: true},
    //2025-10-24T12:21:28.083Z
    data: {type: Date, required: true},
    termino: {type: Boolean, default: false},
    criada: {type: Date, default: Date.now()}
})

module.exports = mongoose.model('Consulta', ConsultaSchema)