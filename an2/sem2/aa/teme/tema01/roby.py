class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def calc_determinant(P, Q, R):
    return Q.x*R.y + P.x*Q.y + R.x*P.y - Q.x*P.y - R.x*Q.y - P.x*R.y

n = int(input())
puncte = []
vs, vd, fv = 0, 0, 0 # viraj stanga, viraj dreapta, fara viraj

for i in range(n):
    x, y = [int(x) for x in input().split()]
    puncte.append(Point(x, y))

i = 0
for i in range(n-2):
    det = calc_determinant(puncte[i], puncte[i+1], puncte[i+2]) 
    if det == 0:
        fv += 1
    elif det < 0:
        vd += 1
    else:
        vs += 1

det = calc_determinant(puncte[n-2], puncte[n-1], puncte[0]) 
if det == 0:
    fv += 1
elif det < 0:
    vd += 1
else:
    vs += 1

print(vs, vd, fv)
