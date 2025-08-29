const path = require('path')
const fs = require('fs')
//caminho para arquivo
const caminhoPath = 'pasta1/caminho/arquivo.pdf'
//caminho do diretorio
console.log(path.dirname(caminhoPath))
//nome do arquivo
console.log(path.basename(caminhoPath))
//nome da extensao
console.log(path.extname(caminhoPath))
//todas as infos do meu arquivo
console.log(path.resolve(caminhoPath))

//crio um path
const pasta1 = "faculdade"
const pasta2 = "termo"
const nomeArquivo = "LPII.pdf"

const pathFinal = path.join('/', pasta1, pasta2, nomeArquivo)
console.log(pathFinal)

//verificar se diretorio existe
if(!fs.existsSync('./dir1')){
    console.log("Diretorio nao existe")
    fs.mkdirSync('dir1')
}else{
    console.log("O diretorio existe")
}