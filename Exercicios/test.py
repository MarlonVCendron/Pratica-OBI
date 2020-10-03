import math

x = 2.2
k = 15
digits = 4

print(math.pow(x, k))

d = pow(10, digits)
z = x % d
for i in range(k-1):
    z *= x
    print(z)
    z %= d
    print(z)
    print()

print(z)
