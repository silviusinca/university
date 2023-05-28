class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return "x: " + str(self.x) + ", y: " + str(self.y)


def calc_determinant(P, Q, R):
    return Q.x * R.y + P.x * Q.y + R.x * P.y - Q.x * P.y - R.x * Q.y - P.x * R.y


# functie care determina daca este sau nu un punct pe segment
def segment(P, Q, R):
    return min(P.x, R.x) <= Q.x <= max(P.x, R.x) and min(P.y, R.y) <= Q.y <= max(P.y, R.y)


n = int(input())
P = []

for i in range(n):
    x, y = [int(x) for x in input().split()]
    P.append(Point(x, y))
P.append(P[0]) # dam push la capatul array-ului la primul element pentru a forma poligonul

m = int(input())
R = []

for i in range(m):
    x, y = [int(x) for x in input().split()]
    R.append(Point(x, y))

# [print(p) for p in P]
# [print(r) for r in R]

for point in R:
    if calc_determinant(P[0], P[n-1], point) == 0 and segment(P[0], point, P[n-1]):
        print("BOUNDARY")
        continue

    if calc_determinant(P[0], P[1], point) == 0 and segment(P[0], point, P[1]):
        print("BOUNDARY")
        continue

    start, end = 2, n-2
    valid = 1
    while calc_determinant(P[0], P[end+1], P[end]) == 0:
        if calc_determinant(P[0], P[end], point) == 0 and segment(P[0], point, P[end]):
            print("BOUNDARY")
            valid = 0
            break
        end -= 1

    while calc_determinant(P[0], P[start-1], P[start]) == 0:
        if calc_determinant(P[0], P[start], point) == 0 and segment(P[0], point, P[start]):
            print("BOUNDARY")
            valid = 0
            break
        start += 1

    if valid != 1:
        continue

    st, dr = 0, n-1

    while dr - st > 1:
        mij = (dr + st) // 2
        if calc_determinant(P[0], P[mij], point) < 0:
            dr = mij
        else:
            st = mij

    if calc_determinant(P[st], P[st+1], point) == 0 and segment(P[st], point, P[st+1]):
        print("BOUNDARY")
    elif calc_determinant(P[st], P[st+1], point) > 0:
        print("INSIDE")
    else:
        print("OUTSIDE")
