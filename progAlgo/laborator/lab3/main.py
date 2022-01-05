def problema1():
    print("")
    # a
    # l1 = [chr(x) for x in range(ord('a'), ord('z') + 1)]
    # print(l1)

    # b
    # n = input("n = ")
    # l2 = [(x if x % 2 == 1 else -x) for x in range(1, n + 1)]
    # print(l2)

    # c
    # l = [int(x) for x in input("numere: ").split()]
    # print(l)
    # l2 = [x for x in l if x % 2 == 0]
    # print(l2)

    # d
    # l3 = [l[i] for i in range(len(l)) if i % 2 == 0]
    # print(l3)

    # e
    # l = [2, 4, 1, 7, 5, 1, 8, 10]
    # rez = [l[i] for i in range(len(l)) if l[i] % 2 == i % 2]
    # print(rez)

    # f
    # l = [1, 2, 3, 4]
    # rez = [(l[i], l[i+1]) for i in range(len(l) - 1)]
    # print(rez)


"""


"""


def problema1g(n):
    return [[f"{x}*{y}={x * y}" for x in range(n)] for y in range(n)]


def problema1h(sir):
    return [sir[i:] + sir[:i] for i in range(len(sir))]


def problema1i(n):
    return [[i for x in range(i)] for i in range(n)]


def problema2a(l):
    a = lambda l: sorted(l)
    return a(l)


def cfun(x):
    return -len(str(x))


def dfun(x):
    return len(set(str(abs(x))))


def efun(x):
    return len(str(x)), x


def seminarex4(l, k):
    smin = 0
    i1, i2 = 0, k-1
    for i in range(k):
        smin += l[i]

    for i in range(1, len(l)-k):
        s = 0
        for j in range(k):
            s += l[i+j]
        if s < smin:
            i1, i2 = i, i+k-1

    return l[:i1] + l[i2+1:]


def funfunfun(el):
    return -len(el)


def seminarex1s(prop):
    l = []
    for el in sorted(prop.split(), key=funfunfun): # sau key=lambda el: -len(el)
        if len(el) >= 2:
            l.append(el)
    return l


def seminarex2skey(el):
    return sum(int(x) for x in str(el)), -el


def seminarex2s(l):
    return sorted(l, key=seminarex2skey) # sau key=lambda el: (sum(int(x) for x in str(el)), -el)


def isprom(l):
    for stud in l:
        prom = 1
        for nota in stud[3]:
            if nota < 5:
                prom = 0
                break
        if prom == 1:
            stud.append(True)
        else:
            stud.append(False)


def afisStudC(stud):
    return stud[2], stud[0], stud[1]


if __name__ == '__main__':
    print("test")
    # l = problema2a([1, 3, 56, 2, 0, -1])
    # print(l)
    # fc = sorted([1, 111, 10, 342163, 12, 33, 2, -2], key=cfun)
    # print(fc)
    # fd = sorted([1, 101, 111, 10, 342163, 12, 33, 2, -2], key=dfun)
    # print(fd)
    # fe = sorted([1, 101, 111, 10, 342163, 12, 33, 2, -2], key=efun)
    # print(fe)


    # seminar liste
    # pb 2
    # l = [1, 123, 0, 3, 56, 2, 0, -1, 67]
    # i1 = i2 = -1
    # for i in range(len(l)):
    #     if l[i] == 0:
    #         if i1 == -1:
    #             i1 = i
    #         else:
    #             i2 = i
    #             break
    #
    # l = l[:i1] + l[i2+1:]
    #
    # print(l)

    # pb 3
    # l = [1, 123, 0, 3, 56, 2, 0, -1, 67]
    # l0 = [x for x in l if x != 0]
    # print(l0)

    # print(seminarex4([1, 123, 0, 3, 56, 2, 0, -1, 67], 3))

    # pb 5
    # l = [int(x) for x in input("vector: ").split()]
    # l = list(set(l))
    # print(l)

    # pb 6
    # l = [float(x) for x in input("vector: ").split()]
    # # 1 -23 33 -4.5 -444 123 0 -1
    # for i in range(1, len(l)):
    #     if l[i-1] < 0:
    #         l = l[:i] + [0] + l[i:]
    # if l[len(l)-1] < 0:
    #     l.append(0.0)
    # print(l)

    # seminar sortari
    # pb 1
    # print(seminarex1s("Ana si Cornel au multe d mere a b c"))

    # pb 2
    # l = [int(x) for x in input("introdu numerele: ").split()]
    # print(seminarex2s(l))

    # pb 3

    # """
    # 3
    # Marineanu Maria 22 10 9 5
    # Mihaliu Dan 22 4 5 10 10
    # Podaru Ilie 21 10 10 8 8
    # """
    # n = int(input())
    # studenti = []
    # for i in range(n):
    #     stud = input().split()
    #
    #     for i in range(2, len(stud)):
    #         stud[i] = int(stud[i])
    #
    #     lnote = []
    #     for i in range(3, len(stud)):
    #         lnote.append(stud[i])
    #
    #     for i in range(3, len(stud)):
    #         stud.pop()
    #
    #     stud.append(lnote)
    #     studenti.append(stud)

    # isprom(studenti)

    # c
    # print(sorted(studenti, key=afisStudC))

    # d ( if stud[-1] is True else
    # studenti = sorted(studenti, key=lambda stud: (stud[2], -stud[-1]))
    # studenti = sorted(studenti, key=lambda stud: (len(list(filter(lambda x: (x < 5), stud[3]))), -(1.0*sum(stud[3])/len(stud[3])), stud[0], stud[1]))
    # print(studenti)

    # matrice si vectori

    # pb 1
    m, n= [int(x) for x in input().split()]
    mat = []
    for i in range(m):
        linie = [int(x) for x in input().split()]
        mat.append(linie)

    print(mat)
    transpusa = []
    transpusa = [[transpusa[i].append(mat[i][j]) for i in range(m)] for j in range(n)]

    print(transpusa)

