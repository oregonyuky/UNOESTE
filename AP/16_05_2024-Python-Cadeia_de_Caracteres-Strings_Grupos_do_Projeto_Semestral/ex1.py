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