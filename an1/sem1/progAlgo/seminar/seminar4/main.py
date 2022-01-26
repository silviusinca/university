def citire(nume_fisier):
    file = open(nume_fisier)
    studenti = []
    for line in file:
        rand = line.split(',')
        stud = (rand[0], int(rand[1]), tuple(int(x) for x in rand[2:]))
        studenti.append(stud)
    file.close()
    return studenti


studenti = citire("studenti.csv")
print(*studenti, sep="\n")
