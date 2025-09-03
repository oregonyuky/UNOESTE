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
            'Relatório Funio e Vendas', 
            'Sair'
        ]
    }]).then((resp)=>{
        const op = resp['op']
        console.log(op)
        if(op === 'Cadastrar Lead'){
            cadastrarLead()
        }
    })
    .catch(err => console.log(err))
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
