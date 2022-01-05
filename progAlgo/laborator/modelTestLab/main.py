# subiectul 1
def citire_matrice(fisier):
    f = open(fisier)
    m = []
    lprim = f.readline().split()
    m.append([int(x) for x in lprim])
    for linie in f:
        l = linie.split()
        if len(l) != len(lprim):
            return None
        m.append([int(x) for x in l])
    f.close()

    return m


def multimi(matrice, *indici):
    reuniune = set()
    inter = set()
    i = 0
    for linie in indici:
        if i == 0:
            l = matrice[linie]
            for el in l:
                if el < 0:
                    inter.add(el)
            i = 1

        l = matrice[linie]
        neg = set()
        poz = set()
        for el in l:
            if el < 0:
                neg.add(el)
            else:
                elpoz = str(el)
                if elpoz[0] == elpoz[-1]:
                    poz.add(el)
        inter = inter.intersection(neg)
        reuniune = reuniune.union(poz)

    return inter, reuniune


"""
# rezolvare 1c)
matrice = citire_matrice("matrice.in")

poz = set()
for i in range(len(matrice)-3, len(matrice)):
    aux, pozAux = multimi(matrice, i)
    poz = poz.union(pozAux)

neg = set()
neg, aux = multimi(matrice, 0, len(matrice)-1)

print(*sorted(poz))
print(len(neg))
"""


# subiectul 2
def modifica_prefix(x, y, prop):
    L = prop.split()
    n = 0
    for cuv in range(len(L)):
        if L[cuv].startswith(x):
            L[cuv] = L[cuv].replace(x, y, 1)
            n += 1

    return " ".join(L), n


def poz_max(l):
    m = max(l)
    poz = []
    for i in range(len(l)):
        if m == l[i]:
            poz.append(i + 1)

    return poz

"""
# rezolvare 2c)
s = input("introdu cuvintele ")
a, b = s.split()

f = open("propozitii.in")
g = open("propozitii.out", "w")

aux = []
for linie in f:
    prop_modif, n = modifica_prefix(a, b, linie)
    g.write(prop_modif + "\n")

    aux.append(n)

print(*poz_max(aux))

f.close()
g.close()
"""


# subiectul 3
f = open("autori.in")
m, n = [int(x) for x in f.readline().split()]

i = 1
d = {}
for linie in f:
    l = linie.split()
    if i <= m:
        d[int(l[0])] = [" ".join(l[1:])]
    else:
        d[int(l[0])].extend([[int(l[1]), int(l[2]), int(l[3]), " ".join(l[4:])]])
    i += 1


# rezolvare 3b)
def sterge_carte(date, cod):
    for codAutor in date:
        for l in date[codAutor][1:]:
            if l[0] == cod:
                date[codAutor].remove(l)
                return date[codAutor][0]

    return None

"""
c = int(input("cod carte: "))
autor = sterge_carte(d, c)
if autor is None:
    print("Cartea nu exista.")
else:
    print(f"Cartea a fost scrisa de {autor}.")
    print(d)
"""

# rezolvare 3c)
def cheie_autor(t):
    return t[1], -t[2], t[3]


def carti_autor(date, cod):
    l = []
    if cod in date:
        laux = []
        for t in date[cod][1:]:
            laux.append(t)
        l = sorted(laux, key=cheie_autor)
        return date[cod][0], l
    return l


c = int(input("cod: "))
if not carti_autor(d, c):
    print("cod incorect")
else:
    nume, lista = carti_autor(d, c)
    print(nume)
    for el in lista:
        print(el[3], el[1], el[2])
