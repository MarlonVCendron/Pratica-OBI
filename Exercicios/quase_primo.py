# import datetime

n,k = [int(x) for x in input().split()]
nums =[int(x) for x in input().split()]

# Contar o tempo
# begin_time = datetime.datetime.now()

quase_primos = 0

count = n
while count > 0:
    divide = False
    for i in range(k):
        if count % nums[i] == 0:
            divide = True
            break

    if not divide:
        quase_primos += 1

    if (count % 2 == 1):
        count -= 1
    count -= 1

print(quase_primos)

# Tempo
# print(datetime.datetime.now() - begin_time)
