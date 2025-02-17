# Here's all the solution of the exercise of the CRISTIANE
There's all exercise that we have done until now 
## 09/05/2024 - Python - Estruturas de Dados - Listas
![image](https://github.com/oregonyuky/UNOESTE/assets/152916454/e8ebcf15-4474-47cb-9a63-3e59597cac27)

### ex1
```py
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
```
### ex2
```py
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
```
