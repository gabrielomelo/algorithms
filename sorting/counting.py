
from random import randint

def countingsort(arr):
    greater = None
    temp = []
    for i in range(0, len(arr)):
        if i < 1:
            greater = arr[i]
        if arr[i] > greater:
            greater = arr[i]

    aux = [0] * (greater + 1)

    for e in arr:
        aux[e] += 1

    for i in range(0, len(aux)):
        dump = [i] * aux[i]
        temp.extend(dump)

    return temp


def random_arr(size, lenght):
    return [randint(0, size) for i in range(0, lenght)]

resultado = countingsort(random_arr(100, 50))

print(resultado)