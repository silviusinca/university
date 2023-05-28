class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return "x: " + str(self.x) + ", y: " + str(self.y)


def calc_determinant(P, Q, R):
    return (P.x*P.x + P.y*P.y)*(Q.x*R.y - R.x*Q.y) + (Q.x*Q.x + Q.y*Q.y)*(R.x*P.y - P.x*R.y) + (R.x*R.x + R.y*R.y)*(P.x*Q.y - Q.x*P.y);


def determinant_mare(A, B, C, D):
    return calc_determinant(A, B, C) + calc_determinant(A, C, D) - calc_determinant(B, C, D) - calc_determinant(A, B, D)


xA, yA = [int(a) for a in input().split()]
xB, yB = [int(a) for a in input().split()]
xC, yC = [int(a) for a in input().split()]
xD, yD = [int(a) for a in input().split()]

A, B, C, D = Point(xA, yA), Point(xB, yB), Point(xC, yC), Point(xD, yD)

AC = determinant_mare(A, B, C, D)
if AC <= 0:
    print("AC: LEGAL")
else:
    print("AC: ILLEGAL")

BD = determinant_mare(B, C, D, A)
if BD <= 0:
    print("BD: LEGAL")
else:
    print("BD: ILLEGAL")
