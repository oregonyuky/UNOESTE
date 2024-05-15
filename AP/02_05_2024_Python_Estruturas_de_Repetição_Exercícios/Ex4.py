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
