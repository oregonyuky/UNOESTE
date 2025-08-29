const fs = require('fs')
console.log('inicio')

fs.writeFile("arquivo.txt", "ola", function(err){
    setTimeout(function(){
        console.log('arquivo criado depois de 1 seg')
    }, 3000)
})
console.log('fim')