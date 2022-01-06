# import math
#
# def frecventa(*fisiere):
#     rez = {}
#     for fisier in fisiere:
#         f = open(fisier)
#         for linie in f:
#             for cuv in linie.split():
#                 if cuv not in rez:
#                     rez[cuv] = 1
#                 else:
#                     rez[cuv] += 1
#         f.close()
#     return rez
#
#
# dict = frecventa("cuvinte1.in", "cuvinte2.in")
# reza = ' '.join(sorted(dict.keys()))
# # print(reza)
#
# frecv1 = frecventa("cuvinte1.in")
# lc = sorted(frecv1.items(), key=lambda cuv: cuv[1], reverse=True) # dictionar.items() returneaza tupluri
# # print(lc)
#
# frecv2 = frecventa("cuvinte2.in")
# frecvMax = max(frecv2.values())
# ld = [cuv for cuv in frecv2 if frecv2[cuv] == frecvMax]
# rezd = min(ld)
# # print(rezd)
#
#
# # print(dict, frecv1, frecv2, sep="\n")
# c = sorted(dict.keys())
# # print(c)
#
# v1 = {}
# v2 = {}
# for cuv in c:
#     if cuv in frecv1:
#         v1[cuv] = frecv1[cuv]
#     elif cuv not in frecv1:
#         v1[cuv] = 0
#
#     if cuv in frecv2:
#         v2[cuv] = frecv2[cuv]
#     elif cuv not in frecv2:
#         v2[cuv] = 0
#
# # print(v1, v2, sep="\n")
#
# s1, s2, s3 = 0, 0, 0
#
# for cuv in c:
#     s1 += v1[cuv] * v2[cuv]
#     s2 += v1[cuv]**2
#     s3 += v2[cuv]**2
#
# s2 = 1.0 * math.sqrt(s2)
# s3 = 1.0 * math.sqrt(s3)
#
# # print(round(1.0*s1/(s2*s3), 2))
#
# p = 2 # p = int(input("p = "))
# # numeFisier = input("numele fisierului: ")
# l = []
# f = open("rime.in")
# dict = {}
#
# for line in f:
#     for cuv in line.split():
#         l.append(cuv)
#
# for cuv in l:
#     if cuv[len(cuv)-p:] not in dict:
#         dict[cuv[len(cuv)-p:]] = [cuv]
#     else:
#         dict[cuv[len(cuv) - p:]].append(cuv)
#
# rez = sorted(dict.items(), key=lambda item: -len(item[1]))
# for i in range(len(rez)):
#     rez[i][1].sort(reverse=True)
#
# g = open("rime.txt", "w")
#
# for lst in rez:
#     g.write(' '.join(lst[1]) + "\n")

# 3
# f = open("test.in")
# g = open("test.out", "w")
#
# nota = 1
# for line in f:
#     aux = line.split("*")
#     a = int(aux[0])
#     l = aux[1].split("=")
#     b = int(l[0])
#     rez = int(l[1])
#
#     if a * b == rez:
#         g.write(f"{a}*{b}={rez} Corect\n")
#         nota += 1
#     else:
#         g.write(f"{a}*{b}={rez} Gresit {a*b}\n")
#
# g.write(f"Nota {nota}")
#
#
# f.close()
# g.close()

# 4 lit mare, 3 lit mici, 4 cifre
f = open("date.in")
g = open("date.out", "w")


