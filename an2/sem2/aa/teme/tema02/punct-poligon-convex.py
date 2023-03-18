class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return("x: " + str(self.x) + ", y: " + str(self.y))

def calc_determinant(P, Q, R):
    return Q.x*R.y + P.x*Q.y + R.x*P.y - Q.x*P.y - R.x*Q.y - P.x*R.y

n = int(input())
P = []

for i in range(n):
    x, y = [int(x) for x in input().split()]
    P.append(Point(x, y))

m = int(input())
R = []

for i in range(m):
    x, y = [int(x) for x in input().split()]
    R.append(Point(x, y))

print([p for p in P])
print([r for r in R])

# computational geometry for competitive programming capitolul 261; raycutting test
