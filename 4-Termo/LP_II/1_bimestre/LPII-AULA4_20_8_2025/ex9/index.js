const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout,

})
readline.question('Qual a sua cor favorita? ', (cor)=>{
    console.log(`A minha cor favorita e: ${cor}`)
    readline.close()
})