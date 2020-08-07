n = int(input())
flechas = []
distancias = []
penalidade = 0

for i in range(n):
    flechas.append([int(x) for x in input().split()])
    distancias.append(((flechas[i][0]**2) + (flechas[i][1]**2))**(1/2))

    count = i
    while (count > 0):
        count -= 1
        if distancias[count] <= distancias[i]:
            penalidade += 1

print(penalidade)
