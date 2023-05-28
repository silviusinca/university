class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return "x: " + str(self.x) + ", y: " + str(self.y)


def calc_determinant(P, Q, R):
    return (P.x*P.x + P.y*P.y)*(Q.x*R.y - R.x*Q.y) + (Q.x*Q.x + Q.y*Q.y)*(R.x*P.y - P.x*R.y) + (R.x*R.x + R.y*R.y)*(P.x*Q.y - Q.x*P.y);


xA, yA = [int(a) for a in input().split()]
xB, yB = [int(a) for a in input().split()]
xC, yC = [int(a) for a in input().split()]

A, B, C = Point(xA, yA), Point(xB, yB), Point(xC, yC)

# print(A, B, C)

P = []
m = int(input())
for i in range(m):
    x, y = [int(x) for x in input().split()]
    P.append(Point(x, y))

for point in P:
    determinant = calc_determinant(A, B, C) + calc_determinant(A, C, point) - calc_determinant(B, C, point) - calc_determinant(A, B, point)
    if determinant == 0:
        print("BOUNDARY")
    elif determinant > 0:
        print("INSIDE")
    else:
        print("OUTSIDE")
