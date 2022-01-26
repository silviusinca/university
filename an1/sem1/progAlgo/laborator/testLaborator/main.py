f = open("drumuri.in")

d = {}
for linie in f:
    l = linie.split("-")

    l[1] = l[1].strip()
    aux = l[1].split()

    lstnume = []
    ok = 0
    lst = []
    for el in aux:
        if el[0].isalpha():
            lstnume.append(el)
        else:
            if ok == 0:
                lst.append(' '.join(lstnume))
                ok = 1
            lst.append(int(el))

    el = l[0].strip()
    if el not in d:
        d[el] = [lst]
    else:
        d[el].append(lst)


def modifica_stare(drumuri, s, o1, o2=""):
    n = 0
    if o2 != "":
        for drum in drumuri[o1]:
            if drum[0] == o2:
                n += 1
                drum[2] = s
                break
    else:
        for drum in drumuri[o1]:
            drum[2] = s
            n += 1

    return n


def accesibil(drumuri, *orase):
    rez = []
    for oras in orase:
        for drum in drumuri[oras]:
            rez.append(drum[0])
    return set(rez)


raspuns = accesibil(d, "Oraselul Mic", "Capitala")
print(raspuns)
