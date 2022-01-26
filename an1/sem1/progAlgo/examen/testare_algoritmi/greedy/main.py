import queue


# La un ghișeu, stau la coadă 𝑛 persoane 𝑝1, 𝑝2, ... , 𝑝𝑛 și pentru fiecare persoană 𝑝𝑖 se cunoaște timpul său
# de servire 𝑡𝑖. Să se determine o modalitate de reașezare a celor 𝑛 persoane la coadă, astfel încât timpul mediu
# de așteptare să fie minim. De exemplu, să considerăm faptul că la ghișeu stau la coadă 𝑛 = 6 persoane,
# având timpii de servire 𝑡1 = 7, 𝑡2 = 6, 𝑡3 = 5, 𝑡4 = 10, 𝑡5 = 6 și 𝑡6 = 4
def ghiseu(t):
    n = len(t)
    t = sorted(t)
    ta = [0] * n
    timp = 0

    for i in range(n):
        timp += t[i]
        ta[i] = timp

    return sum(ta) / n


# print(ghiseu([7, 6, 3, 10, 6, 3]))

def spectacole(fisier):
    f = open(fisier)
    ls = []
    i = 1
    for line in f:
        aux = line.split("-")
        ls.append((i, aux[0].strip(), aux[1].strip()))
        i += 1

    ls = sorted(ls, key=lambda t: t[2])

    rez = [ls[0]]
    for i in range(1, len(ls)):
        if ls[i][1] >= ls[i - 1][2]:
            rez.append(ls[i])

    print(rez)

    f.close()


# spectacole("spectacole.txt")


def spectacoleSali():
    # functie folosita pentru sortarea crescătoare a spectacolelor
    # în raport de ora de început (cheia)
    def cheieOraÎnceput(sp):
        return sp[1]

    # citim datele de intrare din fișierul text "spectacole.txt"
    fin = open("spectacole.txt")
    # lsp = lista spectacolelor, fiecare spectacol fiind memorat
    # sub forma unui tuplu (ID, ora de început, ora de sfârșit)
    lsp = []
    crt = 1
    for linie in fin:
        aux = linie.split("-")
        # aux[0] = ora de început a spectacolului curent
        # aux[1] = ora de sfârșit a spectacolului curent
        lsp.append((crt, aux[0].strip(), aux[1].strip()))
        crt = crt + 1
    fin.close()

    # sortăm spectacolele crescător după orelor de început
    lsp.sort(key=cheieOraÎnceput)
    # sălile vor fi stocate într-o coadă cu priorități în care
    # prioritatea unei săli este dată de ora de terminare a
    # ultimului spectacol planificat în sala respectivă, iar
    # spectacolele planificate în ea vor fi păstrate într-o listă
    sali = queue.PriorityQueue()
    # planificăm primul spectacol în prima sală
    sali.put((lsp[0][2], list((lsp[0],))))
    # parcurgem restul spectacolelor
    for k in range(1, len(lsp)):
        # extragem sala cu ora minimă de terminare a ultimului
        # spectacol planificat în ea
        min_timp_final = sali.get()
        # dacă spectacolul curent lsp[k] poate fi planificat în
        # sala extrasă, atunci îl adăugăm în lista spectacolelor
        # planificate în ea și reintroducem sala în coada cu
        # priorități, dar cu prioritatea actualizată la ora de
        # terminare a spectacolului adăugat
        if lsp[k][1] >= min_timp_final[0]:
            min_timp_final[1].append(lsp[k])
            sali.put((lsp[k][2], min_timp_final[1]))
        # dacă spectacolul curent lsp[k] nu poate fi planificat în
        # sala extrasă, atunci reintroducem sala extrasă în coada
        # cu priorități fără a-i modifica prioritatea și adăugăm
        # o sală nouă în care planificăm spectacolul curent
        else:
            sali.put(min_timp_final)
            sali.put((lsp[k][2], list((lsp[k],))))
    # scriem datele de ieșire în fișierul text "programare.txt"
    fout = open("programare.txt", "w")
    fout.write("Numar minim de sali: " + str(sali.qsize()) + "\n")
    scrt = 1
    while not sali.empty():
        sala = sali.get()
        fout.write("\nSala " + str(scrt) + ":\n")
        for sp in sala[1]:
            fout.write("\t" + sp[1] + "-" + sp[2] + " Spectacol " +
                       str(sp[0]) + "\n")
        scrt += 1
    fout.close()


# spectacoleSali()

def divizori(*l):
    d = {}

    def prim(n):
        if n == 2:
            return 1
        else:
            for i in range(2, n//2):
                if n % i == 0:
                    return 0
        return 1

    for n in l:
        for i in range(2, n):
            if n % i == 0 and prim(i):
                if n not in d:
                    d[n] = [i]
                else:
                    d[n].append(i)

    return d


litere_10 = [chr(x) for x in range(97, 107)]
# print(litere_10)


# 𝐿 = [2, 5, 7, 8, 10, 12, 15, 17, 25] și 𝑆 = 20, trebuie afișate perechile (5, 15) și (8, 12).

def perechi(l, s):
    st = 0
    dr = len(l) - 1
    rez = []
    while st < dr:
        if l[st] + l[dr] == s:
            rez.append((l[st], l[dr]))
            dr -= 1
            st += 1
        elif l[st] + l[dr] < s:
            st += 1
        else:
            dr -= 1
    return rez


# print(perechi([2, 5, 7, 8, 10, 12, 15, 17, 25], 20))


def litere(*cuvinte):
    dict = {}
    for cuv in cuvinte:
        dlit = {}
        for lit in set(cuv):
            dlit[lit] = list(cuv).count(lit)
        dict[cuv] = dlit
    return dict


# print(litere("aerobic", "programator"))

# print([x for x in range(10, 99) if x % 2 == 0 and x % 6 != 0])


def f(v, p, u):
    if u == p:
        print("iterare")
        return 0
    else:
        m = (p+u)//2
        n1 = f(v, p, m)
        n2 = f(v, m+1, u)
        n3 = 0
        for i in range(p, m+1):
            for j in range(m+1, u+1):
                print("iterare")
                if v[i] > v[j]:
                    n3 += 1
        return n1 + n2 + n3


l = [3, 7, 5, 12, 4, 52, 17, 93, 18, 178]

# f(l, 0, len(l) - 1)

# def bkt(k):
#     global s, n
#     for v in range(1, n+1):
#         s[k] = v
#         if s[k] not in s[:k]:
#             if k == n:
#                 print(*s[1:], sep=",")
#             else:
#                 bkt(k+1)
#
#
# n = int(input("n = "))
# # o soluție s va avea n elemente
# s = [0]*(n+1)
# print("Toate permutările de lungime " + str(n) + ":")
# bkt(1)
l = []
for i in range(3):
    aux = [float(x) for x in input().split()]
    l.append(tuple(aux))

print(l)