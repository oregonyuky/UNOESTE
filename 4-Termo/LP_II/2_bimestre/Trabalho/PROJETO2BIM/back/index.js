const express = require('express')
const api = express()
const ConsultaRoutes = require('./src/routes/ConsultaRoutes')
api.use(express.json())
api.use('/consulta', ConsultaRoutes)
const port = 3000
api.get('/teste', (req, resp)=>{
    resp.send('Testando rota')
})
api.listen(port, ()=>{
    console.log(`http://localhost:${port}`)
})