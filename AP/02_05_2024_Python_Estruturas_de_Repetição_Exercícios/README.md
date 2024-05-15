![image](https://github.com/oregonyuky/UNOESTE/assets/152916454/55464c81-8c9f-4bcd-bf5b-8e353d7d43d2)

## Ex1 
```py
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
```
## Ex2
```py
b=0
l=1
maior=0
menor=0
b=int(input("digiteo o numero:"))
while b!=0:
    if b<0:
        print("numero invalido")
    if(l==1):
        maior = b;
        menor = b;
    l=0
    if maior < b and b>0:
        maior = b;
    if menor > b and b>0:
        menor = b;
    b = int(input("digite o numero:"))
print(f"maior numero eh {maior}")
print(f"menor numero eh {menor}")
```
## Ex3
```py
a=0
chapa1=0
chapa2=0
chapa3=0
nulo=0
branco=0
for i in range(1, 9):
    a = int(input("digite 1-chapa1, 2-chapa2, 3, chapa3, 4-voto nulo, 5-voto branco:"))
    if a==1:
        chapa1+=1
    elif a==2:
        chapa2+=1
    elif a==3:
        chapa3+=1
    elif a==4:
        nulo+=1
    else:
        branco+=1
print(f"total de votos do chapa1: {chapa1}")
print(f"total de votos do chapa2: {chapa2}")
print(f"total de votos do chapa3: {chapa3}")
print(f"total de votos nulos: {nulo}")
print(f"total de votos brancos: {branco}")
voto1 = chapa1/8
voto2 = chapa2/8
voto3 = chapa3/8
if voto1 >= 0.5:
    print("chapa1 eh a vencedora")
elif voto2 >= 0.5:
    print("chapa2 eh a vencedora")
elif voto3 >= 0.5:
    print("chapa3 eh a vencedora")
else:
    print("devera ocorrer segundo turno")
```
## Ex4
```py
d = 1
b = 0
c = 0
sim = 0
nao = 0
fs = 0
mn = 0
pessoas = 0

while d != 2:
    d = int(input("Digite 1-continuar, 2-parar: "))
    if d == 2:
        break
    b = input("Digite m-masculino, f-feminino: ")
    c = input("Gostaram da entrevista: sim ou nao: ")
    if c == "sim":
        sim += 1
    else:
        nao += 1
    if b == 'f' and c == "sim":
        fs += 1
    elif b == 'm' and c == "nao":
        mn += 1
    pessoas += 1

print(f"pessoas entrevistadas: {pessoas}")
print(f"pessoas que disseram sim: {sim}")
print(f"pessoas que disseram nao: {nao}")
print(f"percentual de pessoas que disseram nao: {nao*100/pessoas:.2f}%")
print(f"mulheres que disseram sim: {fs}")
print(f"homens que disseram nao: {mn}")
```
