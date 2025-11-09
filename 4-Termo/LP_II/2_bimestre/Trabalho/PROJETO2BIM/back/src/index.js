const express = require('express')
const api = express()
const ConsultaRoutes = require('./routes/ConsultaRoutes')

//api saber que estamos recebendo info e devolvendo info em json
api.use(express.json())

//importar a rota consulta
api.use('/consulta', ConsultaRoutes)


api.listen(3000, ()=>{
    console.log('API online')
})

