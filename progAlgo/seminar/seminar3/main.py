f = open('f.txt')
g = open('comune.txt', 'w')

a = set(int(x) for x in f.readline().split())

for linie in f:
    # b = set(int(x) for x in linie.split())
    # a = a & b
    b = [int(x) for x in linie.split()]
    a = a.intersection(b)

if len(a) == 0:
    g.write("nu e niciun numar")
else:
    for i in a:
        g.write(str(i) + " ")

f.close()
g.close()
