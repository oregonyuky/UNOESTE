gabarito = []
nomes = []
respostas_alunos = []
pontuacao = []

for i in range(1, 11):
    resp_gabarito = input(f"Digite a resposta do exercício {i}: ")
    gabarito.append(resp_gabarito)

continuar = True
while continuar:
    nome_aluno = input("Digite o seu nome: ")
    respostas_aluno = []
    for i in range(1, 11):
        resp_aluno = input(f"Digite sua resposta do Ex{i}: ")
        respostas_aluno.append(resp_aluno)
    nomes.append(nome_aluno)
    respostas_alunos.append(respostas_aluno)
    continuar = int(input("Deseja continuar? (1 - sim, 2 - não): ")) == 1

for aluno, respostas in zip(nomes, respostas_alunos):
    pontuacao_aluno = 0
    for i in range(10):
        if gabarito[i] == respostas[i]:
            pontuacao_aluno += 1
    pontuacao.append(pontuacao_aluno)

for nome, pont in zip(nomes, pontuacao):
    print(f"O aluno {nome} acertou {pont} de 10 questões.")
