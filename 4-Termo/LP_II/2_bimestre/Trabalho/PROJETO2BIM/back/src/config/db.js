//importar o mongoose
const mongoose = require('mongoose')

//definir a url para conexão com o mongo
const url = 'mongodb://localhost:27017/projeto2'

//conexão com o mongo

mongoose.connect(url, {useNewUrlParser: true})

//exportar
module.exports = mongoose