//modulos externos
const chalk = require('chalk')
const inquirer = require('inquirer')
// modulo interno
const fs = require('fs')
console.log('modulos inicializados com sucesso')
menu()
function menu(){
    inquirer.prompt([{
        type: 'list',
        name: 'op',
        message: 'Opcoes',
        choices: [
            'Pipeline de Vendas', //mostrar funil de vendas
            'Cadastrar Lead', //dados do lead
            'Registrar atividades', //tarefas, ligacoes...
            'Atualizar Lead', //atualizar lead depois da atividade
            'Consultar Lead',
            'Remover Lead',
            'Relatório Funio e Vendas', 
            'Sair'
        ]
    }]).then((resp)=>{
        const op = resp['op']
        console.log(op)
        if(op === 'Pipeline de Vendas'){
            exibirPipeline()
        }else if(op === 'Cadastrar Lead'){
            cadastrarLead()
        }else if(op === 'Registrar atividades'){
            registrarAtividade()

        }else if(op === 'Atualizar Lead'){

        }else if(op === 'Consultar Lead'){
            consultarLead()
        }else if(op === 'Remover Lead'){
            removerLead()
        }else if(op === 'Relatório Funio e Vendas'){


        }else if(op === 'Sair'){
            console.log(chalk.bgBlue.black('Sair do programa'))
            //encerrar a execução do sistema
            process.exit()
        }
    })
    .catch(err => console.log(err))
}
function exibirPipeline(){
    console.log(chalk.gray('Contato Inicial'))
    console.log(chalk.gray('Proposta apresentada'))
    console.log(chalk.gray('Negociação'))
    console.log(chalk.gray('Fechamento'))
    menu()
}
function cadastrarLead(){
    console.log(chalk.bgGreen.black('Bem vindo ao CRM'))
    console.log(chalk.green('Opcoes'))
    criarLead()
}
function criarLead(){
    inquirer.prompt([
        {
            name: 'nomeLead',
            message: 'Digite o nome do Lead: '
        }
    ]).then((resp)=>{
        console.log(resp)
        const nomeLead = resp['nomeLead']
        console.log(nomeLead)
        //criar diretorio Leads caso nao existe
        if(!fs.existsSync('leads')){
            fs.mkdirSync('leads')
        }
        //validar se o arquivo json do lead existe
        if(fs.existsSync(`leads/${nomeLead}.json`)){
            console.log(chalk.bgRed.black('Este Lead ja existe'))
            //lead ja existe, solicita um novo nome
            criarLead()
        }
        //se nao existe 
        //criar um arquivo json para o lead
        fs.writeFileSync(`leads/${nomeLead}.json`, '{"historico":""}', 
            function(err){
                console.log(err)
            }
        )
        console.log(chalk.green('Lead criado com sucesso'))
        menu()
    }).catch(err => console.log(err))
}
function registrarAtividade(){
    inquirer.prompt([{
        name: 'nomeLead',
        message: 'Digite o lead que deseja atualizar: '
    }]).then((resp)=>{
        const nomeLead = resp['nomeLead']
        //verificar se o lead existe
        if(!verificaLead(nomeLead)){
            return registrarAtividade()
        }
        //criar a atividade para o lead
        const historico = criarAtividade(nomeLead)
    })
}
function verificaLead(nomeLead){
    //info o usuario que o arquivo nao existe
    if(!fs.existsSync(`leads/${nomeLead}.json`)){
        console.log(chalk.bgRed.black('Este lead nao existe'))
        return false
    }
    return true
}
function criarAtividade(nomeLead){
    inquirer.prompt([
        {
            name: 'nomeVendedor',
            message: 'Digite o nome do vendedor: '
        },
        {
            type: 'list',
            name: 'statusFunil',
            message: 'Qual status do funil de vendas do lead: ',
            choices: ['Inicial', 'Proposta', 'Negociação', 'Fechamento']
        },
        {
            name: 'historico',
            message: 'Digite o historico da atividade realizada: '
        }
    ]).then((resp)=>{
        resp.nomeLead = nomeLead    
        const nomeVendedor = resp['nomeVendedor']
        const data = new Date()
        const ano = data.getFullYear()
        //comeca de 0
        const mes = data.getMonth() + 1
        const dia = data.getDate()
        const hora = data.getHours()
        const min = data.getMinutes()
        const seg = data.getSeconds()
        // var para armazenar o nome do arquivo do log
        const logAtividade = 'log' + dia + mes + ano + hora + min + seg
        if(!fs.existsSync('atividades'))
            fs.mkdirSync('atividades')
        //var com o json para salvar no arquivo
        jsonAtividade = `{"nomeVendedo : "${nomeVendedor}",
                            "nomeLead": "${nomeLead}",
                            "statusFunil": "${resp.statusFunil}",
                            "historico": "${resp.historico}"}`
        fs.writeFileSync(`atividades/${logAtividade}.json`, jsonAtividade, function(err){
            console.log(err)
        })
        //atualizar historico arquivo
        atualizarHistorico(nomeLead, resp.historico)

    }).catch(err => console.log(err))
}
function atualizarHistorico(nomeLead, historico){
    const leadObj = getLead(nomeLead)
    //validar historico do lead
    if(!historico){
        console.log(chalk.bgRed.black('Ocorreu um erro, tente novamente'))
        menu()
    }
    leadObj.historico = leadObj.historico + '\n' + historico
    fs.writeFileSync(`leads/${nomeLead}.json`, 
        //transformar json em texto
        JSON.stringify(leadObj),
        function(err){
            console.log(err)
        }
    )
    console.log(chalk.green('Historico do atualizado com sucesso'))
    menu()
}
function getLead(nomeLead){
    const leadJson = fs.readFileSync(`leads/${nomeLead}.json`, {
        //utf-8 para pegar caracteres especiais
        encoding: 'utf-8',
        //flag para sinalizar que eu so quero ler o arquivo
        flag: 'r'
    })
    //transformar o json em texto
    return JSON.parse(leadJson)
}
function consultarLead(){
    inquirer.prompt([{
        name: 'nomeLead',
        message: 'Digite o lead que deseja consultar: '
    }]).then((resp)=>{
        const nomeLead = resp.nomeLead
        //se nao existe o lead retorna para a mesma funcao
        if(!verificaLead(nomeLead)){
            return consultarLead()
        }
        const leadObj = getLead(nomeLead)
        console.log(chalk.bgBlue.black(`O historico do lead ${nomeLead} eh: ${leadObj.historico}`))
        menu()
    }).catch(err => console.log(err))
}
function removerLead(){
    inquirer.prompt([{
        name: 'nomeLead',
        message: 'Digite o lead que deseja remover: '
    }]).then((resp)=>{
        const nomeLead = resp.nomeLead
        //se nao existe o lead retorna para a mesma funcao
        if(!verificaLead(nomeLead)){
            return consultarLead()
        }
        const leadObj = getLead(nomeLead)
        if(!leadObj){
            console.log(chalk.bgRed.black('Ocorreu um erro '))
            return withdraw()
        }
        //remover o arquivo
        inquirer.prompt([
            {
                type: 'confirm',
                name: 'confirmar',
                message: 'Deseja remover lead? '
            }
        ]).then((resp)=>{
            if(resp.confirmar == true){
                fs.unlinkSync(`leads/${nomeLead}.json`, function(err){
                    console.log(err)
                })
                console.log(chalk.green(`Lead ${nomeLead} excluido com sucesso`))
            }
            menu()
        }).catch(err => console.log(err))
    })
}