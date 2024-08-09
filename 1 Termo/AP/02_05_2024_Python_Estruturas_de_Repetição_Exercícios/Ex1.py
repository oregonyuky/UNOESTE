par=0
soma=0
impar=0
soma_i=0
for i in range(1, 11):
    a = int(input(f"digite o {i}.numero:"))
    if(a%2==0):
        par+=1
        soma+=a
    else:
        impar+=1
        soma_i+=a
print(f"numero de pares: {par}")
print(f"numero de impares: {impar}")
print(f"soma dos pares: {soma}")
print(f"media dos impares: {soma_i/impar}")
