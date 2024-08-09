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
