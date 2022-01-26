print("sub3 subpa progdinam")

# n = int(input())
# cuv = input().split()
n = 7
cuv = ["casa", "apa", "bun", "bine", "fila", "dop", "orar"]

pred = [-1] * n
lmax = [1] * n

for i in range(1, n):
    for j in range(i):
        if (abs(ord(cuv[j][-1]) - ord(cuv[i][0])) == 1) and lmax[i] < lmax[j] + 1:
            pred[i] = j
            lmax[i] = 1 + lmax[j]

imax = 0
for i in range(1, n):
    if lmax[i] > lmax[imax]:
        imax = i
i = imax
sol = []
while i != -1:
    sol.append(cuv[i])
    i = pred[i]

rez = []
for c in cuv:
    if c not in sol:
        rez.append(c)

print(rez)
print(lmax)

# casa apa bun bine fila dop orar