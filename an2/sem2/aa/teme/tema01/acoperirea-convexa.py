class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return("x: " + str(self.x) + ", y: " + str(self.y))

def calc_determinant(P, Q, R):
    return Q.x*R.y + P.x*Q.y + R.x*P.y - Q.x*P.y - R.x*Q.y - P.x*R.y
    
n = int(input())
puncte = []

for i in range(n):
    x, y = [int(x) for x in input().split()]
    puncte.append(Point(x, y))

sol = []

puncte.append(puncte[0])
sol.append(puncte[0])
sol.append(puncte[1])

for i in range(2, n+1):
    sol.append(puncte[i])
    while len(sol) > 2 and calc_determinant(sol[len(sol)-3], sol[len(sol)-2], sol[len(sol)-1]) <= 0:
        x = sol.pop()
        sol.pop()
        sol.append(x)

sol.pop()
print(len(sol))

for solutie in sol:
    print(solutie.x, solutie.y)
