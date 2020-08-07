from math import factorial

n = int(input())
fac_n = factorial(n)
cartas = []
for i in range(fac_n - 1):
    cartas.append([int(x) for x in input().split()])

answer = []

for i in range(n):
    contador = []
    for j in range(n):
        contador.append(0)

    for x in cartas:
        contador[x[i] - 1] += 1
    answer.append(contador.index(min(contador)) + 1)

txt = ''
for c in answer:
    txt += str(c) + ' '

print(txt)
