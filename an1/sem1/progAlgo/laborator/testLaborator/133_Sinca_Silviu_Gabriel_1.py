# Sinca Silviu-Gabriel
# Grupa 133
# Fișierul text text.in conține pe prima linie un cuvânt w nevid format din litere
# mici ale alfabetului englez, iar pe următoarele linii un text în care cuvintele sunt despărțite prin spații și
# semnele de punctuație uzuale. Să se scrie în fișierul text 𝑡𝑒𝑥𝑡. 𝑜𝑢𝑡 toate cuvintele din fișierul
# 𝑡𝑒𝑥𝑡.𝑖𝑛 care au mulțimea literelor inclusă în mulțimea literelor cuvântului 𝑤 sau mesajul
# "𝐼𝑚𝑝𝑜𝑠𝑖𝑏𝑖𝑙" dacă în fișierul de intrare nu există nici un cuvânt cu proprietatea cerută, conform modelului
# din exemplul de mai jos. Cuvintele vor fi scrise grupat, în funcție de mulțimile literelor. Grupele vor fi scrise
# în ordine lexicografică, iar în cadrul fiecărui grup cuvintele vor fi scrise în ordinea descrescătoare a lungimilor
# lor. Fiecare cuvânt va fi scris o singură dată și nu se va face distincție între litere mici și litere mari.

f = open("text.in")
g = open("text.out", "w")

w = sorted(set(f.readline()))
if "\n" in w:
    w.remove("\n")
w = set(w)
dict = {}

for linie in f:
    l = linie.split()
    for cuv in l:
        aux = []
        litCuv = sorted(set(cuv.lower()))
        for lit in litCuv:
            if lit.isalpha():
                aux.append(lit)
        aux = tuple(aux)
        if aux not in dict:
            dict[aux] = [cuv]
        else:
            dict[aux].append(cuv)

n = 0

for key in dict:
    aux = set(key)
    if aux.intersection(w) == aux:
        n += 1
        g.write(f"Literele {sorted(key)}:\n")
        laux = set(dict[key])
        laux = sorted(laux, key=lambda c: -len(c))
        for cuv in laux:
            g.write(f"{cuv}\n")

if n == 0:
    g.write("Imposibil")

f.close()
g.close()
