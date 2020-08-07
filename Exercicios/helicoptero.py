h, p, f, d = [int(x) for x in input().split()]

while(f != h):
    f += d
    f %= 16

    if f == p:
        print('N')
        exit()
print('S')
