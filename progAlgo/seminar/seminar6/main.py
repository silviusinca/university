f = open("proiecte.in")
g = open("proiecte.out")

proiecte = []

for line in f:
    L = line.split()
    proiecte.append((L[0], int(L[1]), float(L[2])))

proiecte = sorted(proiecte, key=lambda x: -x[2])
f.close()

zmax = max(x[1] for x in proiecte)

d = {x: None for x in range(1, zmax + 1)}

for x in proiecte:
    for y in range(x[1], 0, -1):
        if d[y] is None:
            d[y] = x
            break

print(d)




