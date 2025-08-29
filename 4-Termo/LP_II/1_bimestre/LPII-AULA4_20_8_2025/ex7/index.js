const minimist = require('minimist')
const args = minimist(process.argv.slice(2))
const num1 = parseInt(args['num1'])
const num2 = parseInt(args['num2'])

const sub = require('./calc').sub
sub(10, 2)

const soma = require('./calc').sub
soma(10, 2)

console.log('Modulo externo minimist')
sub(num1, num2)
soma(num1, num2)