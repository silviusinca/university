def problema1():
    n = input("n = ")

    if n == n[::-1]:
        print(f"{n} este palindrom")
    else:
        print(f"{n} nu este palindrom")


def problema2():
    n = int(input("n = "))
    a = float(input("Cursul de schimb valutar RON/EURO in ziua 1: "))
    b = float(input("Cursul de schimb valutar RON/EURO in ziua 2: "))
    c = b - a
    ai, bi = 1, 2

    for i in range(3, n + 1):
        x = float(input(f"Cursul de schimb valutar RON/EURO in ziua {i}: "))
        if c < x - b:
            print(c)
            c = x - b
            ai = bi
            bi = i

    print(f"Cea mai mare crestere a fost de {c} RON si a avut loc intre zilele {ai} si {bi}")


def problema3():
    l1 = int(input("Latura 1: "))
    l2 = int(input("Latura 2: "))
    a = l1 * l2

    while l1 != l2:
        if l1 > l2:
            l1 -= l2
        else:
            l2 -= l1

    print(f"Este nevoie de {int(a / (l1 * l1))} placi cu latura de {int(l1)} cm")


def problema4():
    n = int(input("n = "))
    m1 = int(input(f"numarul 1 este: "))
    m2 = None

    for i in range(1, n):
        x = int(input(f"numarul {i + 1} este: "))
        if x > m1:
            m2 = m1
            m1 = x
        if m2 is None or m2 < x < m1:
            m2 = x

    if m1 == m2:
        print("imposibil")
    else:
        print(m1, m2)


def problema5():
    a = int(input("a = "))
    b = int(input("b = "))
    c = int(input("c = "))
    d = b ** 2 - 4 * a * c

    if d < 0:
        print("Ecuatia nu are nicio radacina reala")
    elif d == 0:
        print(f"Ecuatia are o singura radacina reala x = {-b / (2 * a)}")
    else:
        print(
            f"Ecuatia are 2 radacini reale, x1 = {(-b + d ** (1 / 2)) / (2 * a)} si x2 = {(-b - d ** (1 / 2)) / (2 * a)}")


def problema6():
    n = int(input("n = "))
    l = []

    while n:
        l.append(n % 10)
        n = n // 10

    l.sort()
    a, b = 0, 0

    for i in range(len(l)):
        a = a * 10 + l[i]
        b = b * 10 + l[len(l) - i - 1]

    print(a, b)


def problema7():
    x = int(input("x = "))
    n = int(input("n = "))
    p = int(input("p = "))
    m = int(input("n = "))
    k, l = 1, 0

    for i in range(1, m + 1):
        l += x
        if k % n == 0:
            x = x - p*x/100
        k += 1

    print(l)


if __name__ == '__main__':
    problema7()
