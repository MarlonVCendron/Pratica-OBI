import sys

n, m = [int(x) for x in input().split()]
medidas = [int(x) for x in input().split()]
total = 0
ultimo = 0

for x in medidas:
    a = x
    b = m - x

    menor = min(a, b)
    maior = max(a, b)

    if menor < ultimo:
        if maior < ultimo:
            print(-1)
            sys.exit()
        ultimo = maior
    else:
        ultimo = menor
    total += ultimo
print(total)
