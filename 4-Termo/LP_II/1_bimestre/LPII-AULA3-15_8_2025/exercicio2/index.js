const fs = require('fs')
fs.readFileSync('arquivo.txt', 'utf8', (err, texto)=>{
    if(err){
        console.log(err)
        return
    }
    console.log(texto)
})

const data = fs.readFileSync('arquivo.txt', 'utf8');
console.log(data)