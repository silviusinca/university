def problema1():
    s = input("s = ")
    c = s[0]
    s = s.replace(c, '')
    # print(f"Dupa stergerea literei '{c}' sirul devine: \"{s}\" si e de lungime {len(s)}")
    # print("Dupa stergerea literei '{}' sirul devine: \"{}\" si e de lungime {}".format(c, s, len(s)))
    # print("Dupa stergerea literei '{0}' sirul devine: \"{1}\" si e de lungime {2}".format(c, s, len(s)))
    print("Dupa stergerea literei '{litera}' sirul devine: \"{sir}\" si e de lungime {lungime}".format(litera=c, sir=s,
                                                                                                       lungime=len(s)))

    l = [1123, 12444, 523]
    print("primul: {}; al doilea: {}; al treilea:{}".format(l))


def problema2():
    s = input("s = ")
    t = input("t = ")
    try:
        poz = s.index(t)
        while True:
            print(poz, end=" ")
            # poz = s.index(t, poz + 1)       aparitii suprapuse
            poz = s.index(t, poz + len(t))  # aparitii disjuncte
    except:
        print("gata")


def problema3():
    s = input("s = ")
    i = 0
    l = len(s)
    while i < l - i:
        print(s[i:l - i].center(l, " "))
        # print(s[i:l - i].ljust(l, "*"))
        i += 1


def problema4():
    s = "Problemele cu siruri de caracteger nu sunt ggerle! german"
    t = "ger"
    v = "re"
    # a)
    s2 = s.replace(t, v)
    print(s2)

    # b)
    s3 = s.replace(t, v, 2)
    if t in s3:
        print("textul contine prea multe greseli, am corectat maxim 2")

    # b v2)
    k = s.count(t)
    s4 = s.replace(t, v, 2)
    print(s4)
    if k > 2:
        print("textul contine prea multe greseli, am corectat maxim 2")


def problema5():
    p = "ana are    mere  si   ananas     si banane"
    s = "ana"
    t = "ANA"

    L = p.split(" ")
    print(L)
    for i in range(len(L)):
        if L[i] == s:
            L[i] = t

    # for cuv in L:
    #    if cuv == s:
    #        cuv = t # NU MODIFICA LIST

    print(L)
    rez = " ".join(L)
    print(rez)


def problema6():
    codif = "1G10o4l"
    nrcif = 0
    L = []
    for i in range(len(codif)):
        if codif[i].isdigit():
            nrcif += 1
        elif codif[i].isalpha():
            nr = int(codif[i - nrcif: i])
            nrcif = 0
            L += [codif[i] * nr]
    print(L)
    rez = "".join(L)
    print(rez)

    # b
    necod = "Goooooooooollll"
    nrapp = 0
    flit = necod[0]
    rez = ""

    for x in necod:
        if x == flit:
            nrapp += 1
        else:
            rez += str(nrapp) + flit
            flit = x
            nrapp = 1

    rez += str(nrapp) + flit
    print(rez)


def problema7():
    prop = input("Propozitie: ")
    l = prop.split()
    s = 0
    for c in l:
        if c.isdigit():
            s += int(c)
    print(s)


def problema8():
    nume = input("introdu numele: ")
    check = 1

    for lit in nume:
        if lit.isdigit():
            check = 0
            print("breakpoint 0")
            break

    if check == 1:
        ln = nume.split()
        if len(ln) == 2:
            for cuv in ln:
                lcuv = list(cuv)
                if lcuv.count("-") > 1:
                    check = 0
                    print("breakpoint 1")
                    break
                elif lcuv.count("-") == 1:
                    lcuvnou = cuv.split('-')
                    for c in lcuvnou:
                        if len(c) < 3:
                            check = 0
                            print("breakpoint 2")
                            break
                    if not ('A' <= lcuvnou[0][0] <= 'Z' and 'A' <= lcuvnou[1][0] <= 'Z'):
                        check = 0
                        print("breakpoint 3.0")
                        break
                else:
                    if not ('A' <= cuv[0] <= 'Z'):
                        check = 0
                        print("breakpoint 3.5")
                        break
        else:
            print("breakpoint 4")
            check = 0

    if check == 1:
        print("Nume corect!")
    else:
        print("Nume incorect!")


def problema9a():
    text = input("Introdu textul: ")
    k = int(input("Introdu cheia: "))
    rez = ""
    auxMic = list(map(chr, range(ord('a'), ord('z') + 1)))
    auxMare = list(map(chr, range(ord('A'), ord('Z') + 1)))

    for c in range(len(text)):
        if text[c] in auxMic:
            # aflam index-ul caracterului in lista; trebuie sa adaugam k la index si dupa sa aflam restul impartirii la 26
            rez += auxMic[(auxMic.index(text[c]) + k) % 26]
        elif text[c] in auxMare:
            rez += auxMare[(auxMare.index(text[c]) + k) % 26]
        else:
            rez += text[c]

    print(rez)


def problema9b():
    k = int(input("Introdu cheia: "))
    text = input("Introdu textul criptat: ")
    rez = ""
    auxMic = list(map(chr, range(ord('a'), ord('z') + 1)))
    auxMare = list(map(chr, range(ord('A'), ord('Z') + 1)))

    for c in range(len(text)):
        if text[c] in auxMic:
            rez += auxMic[(auxMic.index(text[c]) - k) % 26]
        elif text[c] in auxMare:
            rez += auxMare[(auxMare.index(text[c]) - k) % 26]
        else:
            rez += text[c]

    print(rez)


def problema10():
    a = input("Introdu primul cuvant: ")
    b = input("Introdu al doilea cuvant: ")
    a = list(a)
    b = list(b)

    a.sort()
    b.sort()

    if a.__eq__(b):
        print("Sunt anagrame")
    else:
        print("Nu sunt anagrame")


def problema11a():
    text = input("Introdu textul: ")
    vocale = {"a", "e", "i", "o", "u", "A", "E", "I", "O", "U"}
    textp = ""

    # ========= TRADUCERE IN PASAREASCA =========
    for c in text:
        textp += c
        if c in vocale:
            textp += "p"
            textp += c.lower()

    print(textp)

    # ========= TRADUCERE DIN PASAREASCA =========

    ntext = ""
    for i in range(len(textp)):
        if (textp[i] in vocale and textp[i - 1] == 'p') or (textp[i] == 'p' and textp[i - 1] in vocale):
            continue
        ntext += textp[i]

    print(ntext)


def problema11b():
    # text = input("Introdu textul")
    text = "a-na a-re mul-te me-re ro-sii si de-li-cioa-se"
    print(text)
    l = text.split()

    # ========= TRADUCERE IN PASAREASCA =========
    ltextC = []  # cu cratima
    ltextFC = [] # fara cratima
    for cuv in l:
        listaCuv = cuv.split("-")
        laux = []
        for c in listaCuv:
            aux = ""
            aux += c
            aux += "p"
            aux += c[len(c) - 1]
            laux.append(aux)

        ltextC.append("-".join(laux))
        ltextFC.append("".join(laux))

    textp = " ".join(ltextC)
    print(textp)
    # print(" ".join(ltextFC))

    # ========= TRADUCERE DIN PASAREASCA =========

    nltext = []
    for cuv in textp.split():
        auxl = []
        for c in cuv.split("-"):
            auxl.append(c[:-2])
        nltext.append("-".join(auxl))

    ntext = " ".join(nltext)
    print(ntext)


if __name__ == '__main__':
    problema11b()
