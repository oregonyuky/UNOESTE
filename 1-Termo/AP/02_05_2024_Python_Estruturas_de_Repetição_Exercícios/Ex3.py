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
