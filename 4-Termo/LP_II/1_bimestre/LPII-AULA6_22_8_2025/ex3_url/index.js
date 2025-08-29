//chamando metodo url
const url = require('url')
//exemplo de url para busca de cafe no 'site'
const endereco = 'https://www.site.com/prod?nome=cafe'
//decompor a url
const parseUrl = new url.URL(endereco)
console.log(parseUrl.host)
console.log(parseUrl.pathname)
console.log(parseUrl.search)
console.log(parseUrl.searchParams)
console.log(parseUrl.searchParams.get('nome'))

