def frecventa(*numeFisiere):
    d = {}
    for fisier in numeFisiere:
        f = open(fisier)
        for linie in f:
            for cuv in linie.split():
                # if cuv not in d:
                #     d[cuv] = 1
                # else:
                #     d[cuv] += 1
                # SAU
                d[cuv] = d.get(cuv, 0) + 1
        f.close()
    return d


dictionar = frecventa("cuvinte1.in", "cuvinte2.in")

print(sorted(dictionar.keys()))
