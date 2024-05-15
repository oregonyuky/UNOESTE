## Ex1
```py
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
```
## Ex2
```py
list_carro = []
list_km = []
for i in range(0, 5):
    print(f"Veiculo {i+1}")
    carro = input("Nome: ")
    km = float(input("Digite Km por litro: "))
    list_carro.append(carro)
    list_km.append(km)
for i in range(0, 5):
    consumo_litros = 1000 / list_km[i]  
    custo_total = 5.95 * consumo_litros  
    print(f"{i+1}-{list_carro[i]}   {list_km[i]:.2f} km/l - {consumo_litros:.2f} litros - R${custo_total:.2f}")
menor_consumo = min(list_km)
indice_menor_consumo = list_km.index(menor_consumo)
print(f"O veículo com menor consumo é o {list_carro[indice_menor_consumo]} com {menor_consumo:.2f} km/l.")
```
