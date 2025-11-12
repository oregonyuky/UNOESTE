const express = require('express')
const api = express()
const cors = require('cors')
const ConsultaRoutes = require('./routes/ConsultaRoutes')

//api saber que estamos recebendo info e devolvendo info em json
api.use(express.json())
api.use(cors())

//importar a rota consulta
api.use('/consulta', ConsultaRoutes)


api.listen(3000, ()=>{
    console.log('API online')
})

