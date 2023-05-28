class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return "x: " + str(self.x) + ", y: " + str(self.y)


def calc_determinant(P, Q, R):
    return Q.x * R.y + P.x * Q.y + R.x * P.y - Q.x * P.y - R.x * Q.y - P.x * R.y


def segment(P, Q, R):
    return min(P.x, R.x) <= Q.x <= max(P.x, R.x) and min(P.y, R.y) <= Q.y <= max(P.y, R.y)


def intersectie(A, B, C, D):
    a1 = B.y - A.y
    b1 = A.x - B.x
    c1 = a1 * A.x + b1 * A.y  # AB

    a2 = D.y - C.y
    b2 = C.x - D.x
    c2 = a2 * C.x + b2 * C.y  # CD

    determinant = a1*b2 - a2*b1
    if determinant == 0:
        return

    x = (b2 * c1 - b1 * c2) / determinant

    return x


n = int(input())
P = []
maxX = float('-inf')

for i in range(n):
    x, y = [int(x) for x in input().split()]
    maxX = max(x, maxX)
    P.append(Point(x, y))
P.append(P[0]) # dam push la capatul array-ului la primul element pentru a forma poligonul

m = int(input())
Q = []
for i in range(m):
    x, y = [int(x) for x in input().split()]
    Q.append(Point(x, y))


for point in Q:
    nr_intersectii = 0

    for i in range(n):
        # print(i)
        A = P[i]
        B = P[i+1]

        if calc_determinant(A, B, point) == 0 and segment(A, point, B):
            print("BOUNDARY")
            nr_intersectii = -1
            break

        if (A.y < point.y and B.y < point.y) or (A.y >= point.y and B.y >= point.y):
            continue

        punct_intersectie = intersectie(A, B, point, Point(maxX + 2, point.y))
        if punct_intersectie > point.x:
            nr_intersectii += 1

    if nr_intersectii != -1:
        if nr_intersectii % 2 == 0:
            print("OUTSIDE")
        else:
            print("INSIDE")