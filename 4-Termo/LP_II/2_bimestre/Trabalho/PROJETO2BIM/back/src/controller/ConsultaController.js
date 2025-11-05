const ConsultaModel = require('../model/ConsultaModel')
class ConsultaController{
    static async criar(req, resp){
        const consulta = new ConsultaModel(req.body)
        await consulta
            .save() 
            .then(resposta =>{
                return resp.status(200).json(resposta)
            })
            .catch(erro=>{
                return resp.status(200).json(erro)
            })
    }
}
module.exports = ConsultaController