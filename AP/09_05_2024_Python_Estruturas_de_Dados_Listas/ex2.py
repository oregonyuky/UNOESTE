lista = []
lista_impar = []
lista_par = []
d = 1

for i in range(1, 9):
    a = int(input(f"Digite número {d}: "))
    lista.append(a)
    d += 1

for i in range(len(lista)):
    if lista[i] % 2 != 0:
        lista_impar.append(lista[i])
    else:
        lista_par.append(lista[i])
print("Numeros:")
for num in lista:
    print(num)
print("Números ímpares:")
for num in lista_impar:
    print(num)

print("Números pares:")
for num in lista_par:
    print(num)
