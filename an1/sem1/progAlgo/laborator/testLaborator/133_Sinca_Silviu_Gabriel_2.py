# Sinca Silviu-Gabriel
# Grupa 133
# Fișierul "date.in" are n linii cu următoarea structură: pe linia i sunt prezente,
# separate prin câte un spațiu, n numere naturale reprezentând elementele de pe linia i dintr-o matrice,
# ca în exemplul de mai jos.

f = open("date.in")


def citire_matrice():
    mat = []
    for linie in f:
        mat.append([int(x) for x in linie.split()])
    return mat


# b
def modifMatrice(mat, ch, x=0, y=0):
    if ch == "c":
        for i in range(len(mat)):
            mat[i][x], mat[i][y] = mat[i][y], mat[i][x]
    elif ch == "d":
        for i in range(len(mat)):
            for j in range(len(mat)):
                if i == j:
                    mat[i][j], mat[i][len(mat)-i-1] = mat[i][len(mat)-i-1], mat[i][j]


matrix = citire_matrice()
print(matrix)
modifMatrice(matrix, "d")
print(matrix)

f.close()