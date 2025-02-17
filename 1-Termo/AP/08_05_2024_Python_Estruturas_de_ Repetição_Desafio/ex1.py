import random 
c=1;
b=0;
while b!=7 and b!=11 and b!=2 and b!=3 and b!=12 and c!=3:
    b = random.randint(2, 12)
    print(f"rodada {c}: voce tirou {b}")
    if b==7 or b==11:
        print("voce ganhou")
    elif b==2 or b==3 or b==12:
        print("voce perdeu")
    else:
        print("voce ganhou um ponto")
    if c>1:
        if b==7 and b==2 and b==3 and b==12:
            print("voce perdeu")
        else:
            print("voce ganhou")
    c+=1;
