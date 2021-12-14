# 1
def cand_maj(lista):
    d = {}

    for x in lista:
        if x in d:
            d[x] += 1
            if d[x] > len(lista) // 2:
                return x
        else:
            d[x] = 1
    return None


l1 = [1, 5, 5, 1, 1, 5]
l2 = [7, 3, 7, 4, 7, 7]

# print(cand_maj(l1))
# print(cand_maj(l2))


def cand_maj_v2(voturi):
    avantaj = 0
    castigator = None

    for x in voturi:
        if avantaj == 0:
            castigator = x
            avantaj = 1
        elif castigator == x:
            avantaj += 1
        else:
            avantaj -= 1

    if avantaj != 0 and voturi.count(castigator) > len(voturi) // 2:
        return castigator

    return None


# print(cand_maj_v2(l1))
# print(cand_maj_v2(l2))


def perechi(L, S):
    M = set(L)

    for x in L:
        if x >= S // 2:
            break
        if S-x in M:
            print (x, S-x)


L = [2, 5, 7, 8, 10, 12, 15, 17, 25]
S = 20

left, right = 0, len(L) - 1

while left < right:
    if L[left] + L[right] == S:
        print(L[left], L[right])
        left += 1
        right -= 1
    elif L[left] + L[right] < S:
        left += 1
    else:
        right -= 1

