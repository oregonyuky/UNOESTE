const minimist = require('minimist')
const chalk = require('chalk')

const args = minimist(process.argv.slice(2))
console.log('Qual a soma de  5+3?')
const resp = parseInt(args['resposta'])

if(resp==8){
    console.log(chalk.green('Resposta correta'))
}else{
    console.log(chalk.bgRed('Resposta incorreta'))
}