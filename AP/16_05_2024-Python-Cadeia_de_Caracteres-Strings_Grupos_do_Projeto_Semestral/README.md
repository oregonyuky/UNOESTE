## Ex1
```py
a=''
cont=0
a = input("Digite uma frase: ")
b = ['a','e','i','o','u','A','E','I','O','U',
     'ã','á','é','í','ó','ú','Á','É','Í','Ó','Ú','Ã']
for i in range(0, len(a)):
    for j in range(0, len(b)):
        if a[i] == b[j]:
            cont+=1
print(f"Quantidade de vogais: {cont}")
```
## Ex2
```py
a=''
b=''
frase=''
list_frase=[]
lista=[]
a = input("Digite 1 caractere: ")
b = input("Digite outra caractere: ")
frase = input("Digite uma frase: ")
print(f"frase eh {frase.replace(a, b)}")
```
