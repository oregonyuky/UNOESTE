## Ex1
```py
a=''
b=''
list_a=[]
list_b=[]
nome=''
res=0
cont=0
for i in range(0, 10):
    a = input(f"Digite o gabarito do Ex{i+1}");
    list_a.append(a)
while res!=2:
    nome = input("Digite seu nome:")
    list_b=[]
    cont=0
    for i in range(0, 10):
        b = input(f"Digite a sua resposta do Ex {i+1}")
        list_b.append(b)
        if list_a[i] == list_b[i]:
            cont+=1
    print(f"{nome} tirou {cont} pontos de 10")
    res = int(input("Deseja continuar: 1-sim, 2-nao?"))

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
