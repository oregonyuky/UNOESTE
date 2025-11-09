const ConsultaModel = require('../model/ConsultaModel')

//data e hora do momento
const hoje = new Date()

//recuperar começo e fim do dia
const  {startOfDay, endOfDay, startOfWeek, endOfWeek} = require('date-fns')

class ConsultaController{
    //função para criar a consulta
    static async criar(req, resp){
        //recuperar infos do body da req.
        //dados obrigatórios
        const consulta = new ConsultaModel(req.body)

        //salvar no banco
        await consulta
            .save()//salvar no mongo
            .then(resposta =>{
                return resp.status(200).json(resposta)
            })
            .catch(erro=>{
                return resp.status(500).json(erro)
            })
    }

    static async atualizar(req, resp){

        //resgatar os dados da consulta pelo id (findbyid)
        //passar pelo body da req as informações para a alteração
        //quando for feita a aatualização o mongo identifica se mudou 
        //algum atributo e atualiza a os campos alterados
        //propriedade new: true --> sempre retorna os dados da consulta
        //atualizados na resposta
        await ConsultaModel.findByIdAndUpdate(
            {'_id': req.params.id},
            req.body,
            {new: true}
            )
            .then(resposta =>{
                return resp.status(200).json(resposta)
            })
            .catch(erro=>{
                return resp.status(500).json(erro)
            })
    }

    static async listar(req, resp){
        //listar consultas
        //por tipo
        //operador in para procurar entre os dados existentes quais 
        // consultas são do tipo passado por parametro
        await ConsultaModel.find(
            {'tipo': {'$in':req.body.tipo}}
            )
            //organizar as consultas por data crescente
            .sort('data')
            .then(resposta =>{
                return resp.status(200).json(resposta)
            })
            .catch(erro=>{
                return resp.status(500).json(erro)
            })
    }

    static async buscar(req, resp){
        //passar por parametro o id da consulta que quero buscar
        await ConsultaModel.findById(req.params.id)
            .then(resposta =>{
                return resp.status(200).json(resposta)
            })
            .catch(erro=>{
                return resp.status(500).json(erro)
            })
    }

    static async deletar(req, resp){
        //passar por parametro o id da consulta que quero buscar
        await ConsultaModel.deleteOne({'_id':req.params.id})
            .then(resposta =>{
                return resp.status(200).json(resposta)
            })
            .catch(erro=>{
                return resp.status(500).json(erro)
            })
    }

    static async concluida(req, resp){

        await ConsultaModel.findByIdAndUpdate(
            {'_id': req.params.id},
            {'termino': req.params.termino},
            {new: true}
            )
            .then(resposta =>{
                return resp.status(200).json(resposta)
            })
            .catch(erro=>{
                return resp.status(500).json(erro)
            })
    }


    static async atrasadas(req, resp){

        await ConsultaModel.find(
            //operador lt --> less then --> menor que
            {'data': {'$lt':hoje},
            'termino': false}
            )
            .sort('data')
            .then(resposta =>{
                return resp.status(200).json(resposta)
            })
            .catch(erro=>{
                return resp.status(500).json(erro)
            })
    }

    static async consultaHoje(req, resp){

        await ConsultaModel.find(
            //operador gte --> maior igual que
            //operador lte --> menor igual que
            {'data': {'$gte':startOfDay(hoje), '$lte': endOfDay(hoje)}})
            .sort('data')
            .then(resposta =>{
                return resp.status(200).json(resposta)
            })
            .catch(erro=>{
                return resp.status(500).json(erro)
            })
    }

    static async consultaSemana(req, resp){

        await ConsultaModel.find(
            //operador gte --> maior igual que
            //operador lte --> menor igual que
            {'data': {'$gte':startOfWeek(hoje), '$lte': endOfWeek(hoje)}})
            .sort('data')
            .then(resposta =>{
                return resp.status(200).json(resposta)
            })
            .catch(erro=>{
                return resp.status(500).json(erro)
            })
    }



}
//expostar a minha classe
module.exports = ConsultaController