const alunos = []
function cadastrarAluno(nome, idade, cpf){
    aluno = {}
    aluno.nome = nome
    aluno.idade = idade 
    aluno.cpf = cpf 
    alunos.push(aluno)
}
cadastrarAluno("Joao", 30, "1212121212")
cadastrarAluno("Ana", 31, "232323232C")
cadastrarAluno("Maria", 32, "2442424242")
console.log(alunos)
const disciplinas = []
function cadastrarDisciplinas(nome, termo, ementa){
    disciplina = {}
    disciplina.nome = nome
    disciplina.termo = termo
    disciplina.ementa = ementa
    disciplinas.push(disciplina)
}
cadastrarDisciplinas("ATP1", 1, "Algoritmos e tec...")
cadastrarDisciplinas("LPII", 4, "linguagem de prog...")
console.log(disciplinas)
alunos[0].disciplina = disciplinas[1]
console.log(alunos)
