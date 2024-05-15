num = int(input("digite o numero"))
lista = []
while num != 0:
    lista.append(num)
    num = int(input("digite o numero"))
menor = lista[0]
maior = lista[0]
for i in range(1, len(lista)):
    if menor > lista[i]:
        menor = lista[i]
    if maior < lista[i]:
        maior = lista[i]
print(lista)
print(f"maior numero: {maior}")
print(f"menor numero: {menor}")
