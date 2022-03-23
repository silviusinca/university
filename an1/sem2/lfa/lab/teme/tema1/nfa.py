input = open("input.txt")
output = open("output.txt", 'w')

"""
4
1 2 3 4
5
1 1 a
1 1 b
1 2 a
2 3 a
3 4 a
1
1
4
4
abab
abaa
aaaa
abbb
"""

# citire de input
N = int(input.readline())
stari = [int(x) for x in input.readline().split()]
stari.sort()
M = int(input.readline())

tranzitii = []
for i in range(M):
    aux = input.readline().split()
    tranzitie = [(int(aux[0]), int(aux[1])), aux[2]]
    tranzitii.append(tranzitie)  # adaug fiecare tranzitie in lista

print(tranzitii)

S = int(input.readline())  # stare intiala

nrF = int(input.readline())
stariFinale = [int(x) for x in input.readline().split()]

nrCuv = int(input.readline())
for i in range(nrCuv):
    cuv = input.readline().strip()

    listaStari = [S]  # listaStari reprezinta o lista cu starile posibile; incepe cu starea initiala
    for lit in cuv:
        listaStariActuale = []  # in lista asta adaug toate starile noi
        for tranzitie in tranzitii:
            for stare in listaStari:
                if stare == tranzitie[0][0] and lit == tranzitie[1]:
                    listaStariActuale.append(tranzitie[0][1])
        listaStari = listaStariActuale
    print(listaStari)

    for stare in listaStari:
        if stare in stariFinale:
            output.write("DA\n")
            break
    else:
        output.write("NU\n")

input.close()
output.close()


