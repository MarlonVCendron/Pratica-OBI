n, m = [int(x) for x in input().split()]
instrucoes = []

for i in range(m):
    instrucoes.append([int(x) for x in input().split()])

fita = [0] * n

for i in instrucoes:
    if i[0] == 3:
        print(fita[i[1]-1])
    else:
        index = i[1]
        v = i[2]
        while True:
            fita[index - 1] += v
            v -= 1
            index += (1) if (i[0] == 1) else (-1)

            if (v == 0) or (index == 1) or (index == n):
                break
