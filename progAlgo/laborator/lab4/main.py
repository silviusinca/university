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
#
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
#
# 4 lit mare, 3 lit mici, 4 cifre
# import random, string
#
#
# def generatePassword():
#     password = random.choice(string.ascii_uppercase)
#     for i in range(3):
#         password += random.choice(string.ascii_lowercase)
#     for i in range(4):
#         password += random.choice(string.digits)
#     return password
#
# f = open("date.in")
# g = open("date.out", "w")
#
# stud = []
# for student in f:
#     lst = student.split()
#     login = lst[1].lower() + "." + lst[0].lower() + "@s.unibuc.ro,"
#     login += generatePassword()
#     g.write(f"{login}\n")
#
# 5
#
# def negative_pozitive(l):
#     lneg, lpoz = [], []
#
#     for el in l:
#         if el < 0:
#             lneg.append(el)
#         elif el > 0:
#             lpoz.append(el)
#
#     return lneg, lpoz
#
#
# l1, l2 = negative_pozitive([-1, 1, 5123, -324, 44])
# fisier = input("nume fisier: ")
# g = open(fisier, "w")
# g.write(f"{sorted(l1)}\n{sorted(l2)}")
#
# # 6
# import random
# import string
#
# f = open("elevi.in")
# elevi = {}
#
# for linie in f:
#     l = linie.split()
#     elevi[l[0]] = [l[1], l[2], [int(x) for x in l[3:]]]
#
# f.close()
#
# print(elevi)
#
#
# def cresteNota(cnp, d):
#     if cnp in d:
#         d[cnp][2][0] += 1
#         return d[cnp][2][0]
#     return None
#
#
# # cnp = input("cnp: ")
# # print(cresteNota(cnp, elevi))
# # print(cresteNota("2402900000041", elevi))
# # print(cresteNota("2402900000040", elevi))
#
# def adaugaNote(cnp, lnote, d):
#     if cnp in d:
#         d[cnp][2].extend(lnote)
#         return d[cnp][2]
#     return None
#
#
# # print(adaugaNote("2402900000041", [10, 8], elevi))
# # print(adaugaNote("2402900000040", [10, 8], elevi))
#
#
# def stergeElev(cnp, d):
#     if cnp in d:
#         del(d[cnp])
#     return None
#
# # stergeElev("2402900000041", elevi)
# # print(elevi)
#
#
# rezd = []
#
# for cnp in elevi:
#     aux = [elevi[cnp][0], elevi[cnp][1]]
#
#     for nota in elevi[cnp][2]:
#         aux.append(nota)
#
#     rezd.append(aux)
#
# rezd = sorted(rezd, key=lambda el: (1.0*sum(el[2:])/(len(el)-2), el[0]), reverse=True)
# # print(rezd)
#
#
# def genereaza_coduri(d):
#     for cnp in d:
#         cod = ""
#
#         for i in range(3):
#             cod += random.choice(string.ascii_letters)
#         for i in range(3):
#             cod += random.choice(string.digits)
#
#         d[cnp].append(cod)
#
#
# genereaza_coduri(elevi)
# print(elevi)
#
#
# 7
#
# lst = []
#
#
# def citireLista():
#     n = int(input("n = "))
#     for i in range(n):
#         lst.append(int(input()))
#     return None
#
#
# citireLista()
#
#
# def chestieB(s, x, i=0, j=0):
#     if i != j:
#         for k in range(i, j+1):
#             if s[k] > x:
#                 return s[k]
#     return -1
#
#
# # lstCuv = ["c", "b", "a"]
# ok = 1
# for i in range(len(lst)):
#     if chestieB(lst, lst[i], i, len(lst)-1) != -1:
#         ok = 0
#         break
#
# if ok == 1:
#     print("Da")
# else:
#     print("Nu")

# 8
# def liste_x(x, *liste):
#     nr = 0
#     for lista in liste:
#         if x in lista:
#             nr += 1
#     return nr


# n = liste_x(3, [1, 5, 7], [3], [1, 8, 3], [])
# print(n)

# rez = None


# def liste_xb(x, *liste):
#     global rez
#     nr = 0
#     for lista in liste:
#         if x in lista:
#             nr += 1
#     rez = nr


# liste_xb(3, [1, 5, 7], [3], [1, 8, 3], [])
# print(rez)

# 9

# def alipire(*numere):
#     rez = 0
#     for n in numere:
#         aux = sorted(str(n))
#         rez = 10*rez + int(aux[-1])
#
#     return rez
#
#
# print(alipire(4251, 73, 8, 133))
#
#
# def bazadoi(a, b, c):
#     if alipire(a,b,c) == 111:
#         return True
#     return False
#
#
# print(bazadoi(1001, 17, 100))

# 10
def cautare_cuvant(cuv, nume_fis_out, *nume_fis_in):
    g = open(nume_fis_out, "w")
    for fisier in nume_fis_in:
        f = open(fisier)
        i = 1
        poz = []
        for linie in f:
            if linie.lower().__contains__(cuv):
                poz.append(i)
            i += 1
        g.write(f"{fisier} {' '.join(str(x) for x in poz)}\n")


cautare_cuvant("floare", "rez.txt", "eminescu.txt", "paunescu.txt")


