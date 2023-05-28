class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return "x: " + str(self.x) + ", y: " + str(self.y)


n = int(input())
P = []

for i in range(n):
    x, y = [int(x) for x in input().split()]
    P.append(Point(x, y))
P.append(P[0])

st = dr = sus = jos = P[0]
indexSt = indexDr = indexSus = indexJos = 0

for i in range(1, n):
    if P[i].x < st.x:
        st = P[i]
        indexSt = i

    if P[i].x > dr.x:
        dr = P[i]
        indexDr = i

    if P[i].y > sus.y:
        sus = P[i]
        indexSus = i

    if P[i].y < jos.y:
        jos = P[i]
        indexJos = i

xMonoton = yMonoton = 1

index = indexJos + 1
while index % n != indexSus:
    if P[index % n - 1].y > P[index % n].y:
        yMonoton = 0
        break
    index += 1

if yMonoton:
    index = indexJos - 1
    while index != indexSus:
        if index == -1:
            index = n - 1
        if index == indexSus:
            break

        if P[index].y < P[index+1].y:
            yMonoton = 0
            break

        index -= 1

index = indexSt + 1
while index % n != indexDr:
    if P[index % n].x < P[index % n - 1].x:
        xMonoton = 0
        break
    index += 1

if xMonoton:
    index = indexSt - 1
    while index != indexDr:
        if index == -1:
            index = n - 1
        if index == indexDr:
            break

        if P[index].x < P[index + 1].x:
            xMonoton = 0
            break

        index -= 1

if xMonoton:
    print("YES")
else:
    print("NO")

if yMonoton:
    print("YES")
else:
    print("NO")

