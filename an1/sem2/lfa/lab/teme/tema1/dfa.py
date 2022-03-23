input = open("input.txt")
output = open("output.txt", 'w')
"""

7
1 2 3 4 5 6 7
9
1 2 a
1 3 b
1 4 c
2 5 b
3 5 c
3 6 a
4 6 e
5 7 c
6 7 r
1
2
6 7
4
abc
bc
cer
bar

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
    tranzitii.append(tranzitie) # adaug fiecare tranzitie in lista

S = int(input.readline())  # stare intiala

nrF = int(input.readline())
stariFinale = [int(x) for x in input.readline().split()]

nrCuv = int(input.readline())
for i in range(nrCuv):
    cuv = input.readline().strip()
    st = S # voi lua st drept stare curenta si o voi initializa cu S; voi verifica pe parcurs daca tranzitiile exista
    for lit in cuv:
        ok = 0
        for tranzitie in tranzitii:
            if st == tranzitie[0][0] and lit == tranzitie[1]:
                st = tranzitie[0][1]
                print(st, end=" ")
                break
        else:
            output.write("NU\n")
            break
    else:
        if st in stariFinale:
            output.write("DA\n")
        else:
            output.write("NU\n")
    print("")

input.close()
output.close()
