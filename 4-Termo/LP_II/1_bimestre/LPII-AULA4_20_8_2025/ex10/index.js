const inquirer = require('inquirer')

inquirer.prompt([
    {
        name: 'idade',
        message: 'Qual a sua idade?',
    },
    {
        name: 'mes',
        message: 'Qual mes voce nasceu?',
    },
    {
        name: 'pais',
        message: 'Qual pais voce nasceu?',
    },
]).then((resp)=>{
    console.log(resp)
    ano = (2025-resp.idade)
    if(resp.mes > 8)ano--;
    console.log(ano)
}).catch(err => console.log(err))