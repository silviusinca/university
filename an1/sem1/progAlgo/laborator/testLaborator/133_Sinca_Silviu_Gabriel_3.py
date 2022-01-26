# Sinca Silviu-Gabriel
# Grupa 133
# Fișierul text drumuri.in conține informații despre drumurile dintre orașele unei
# țări. O linie din fișier are următoarea structură: Nume_Oras_1 - Nume_Oras_2 distanta stare_drum unde Nume_Oras_1
# și Nume_Oras_2 sunt numele a două orașe (un nume este un șir de cuvinte separate prin câte un spațiu),
# distanta este lungimea drumului dintre cele două orașe, iar stare_drum (număr natural) este un număr natural între
# 0 și 5 reprezentând calitatea drumului între cele două orașe. Pe un drum se poate circula doar într-un sens,
# respectiv de la Nume_Oras_1 la Nume_Oras_2.

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
