
if __name__ == '__main__':
    # NUMERE COMPLEXE
    x = 1 + 2j  # x = 1 + 2i
    y = 2 - 3j
    print(x + y)  # 3 - i

# Tipuri secventiale:
    # siruri de caractere
    # tupluri:
    T = (100, -7, 30, 18)
    # list:
    L = [100, -7, 30, 18]

# tipuri multime:
    # set
    # frozenset

# tipul dictionar(tablouri asociative = cheie:valoare):
    # dict
    note = {"Popescu Ion": 10, "Ionescu Andrei": 9.90}
    print(note["Popescu Ion"])

# PYTHON -> ALOCARE DINAMICA

    # un tip de date = o clasa, o valoare = un obiect din clasa corespunzatoare
    # variabilele sunt declarate dinamic

    # caract unei variabile:
    # tip de date asociat: type(variabila)
    # valoare
    # identificator: id(variabila)

    x = 100
    print()
    print("x =", x)
    print(type(x))
    print(id(x))
    y = x
    print("y =", y)
    print(id(y))

    y = x + 1
    print("y =", y)
    print(id(y))
    print()

    x = "Ana are mere"
    print("x =", x)
    print(type(x))

    print()

    # INTREGII INTRE -5 SI 256 SUNT DIRECT ALOCATI IN MEMORIE

    x = 100
    y = 100
    print(id(x) == id(y))

    y = x + 1
    print(id(x) == id(y))

    y = y - 1
    print(id(x) == id(y))

    print()


    i = 1
    while i < 10:
        print(i, end=", ")
        i = i + 1

    print()
    x = 1
    y = 2
    print(x, y, sep="+")

    print()
    mere = 10
    pere = 20
    print(f"Ana are {mere} si {pere}, deci are {mere+pere} fructe!")
    print()

    x = int(input("introduceti valoarea lui x: "))
    y = input("introduceti valoarea lui y: ")
    print(type(y))
    y = int(y)
    print(x+y)

    print()
    x = 7
    if 1 <= x <= 10:
        print("DA")
    else:
        print("NU")

    x = 71
    y = 71
    print(x is y)

    print()

    x = 712222
    y = 712222 + 1
    y = y - 1
    print(x is y) # id(x) == id(y)

    print()
    sir = "Ana are mere"
    print("na" in sir)

    print()
    lista = [1, 2, 3, 4, 5]
    print(33 in lista)
