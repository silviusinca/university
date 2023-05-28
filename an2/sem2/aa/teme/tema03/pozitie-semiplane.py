
n = int(input())
planuri = []
for i in range(n):
    a, b, c = [float(x) for x in input().split()]
    planuri.append([a, b, c])

m = int(input())
for i in range(m):
    x, y = [float(x) for x in input().split()]
    xMin = yMin = float('inf')
    xMax = yMax = float('-inf')
    for plan in planuri:
        print(plan)
        a, b, c = plan[0], plan[1], plan[2]
        # orizontal
        if a == 0:
            if b > 0:
                if yMin > -c/abs(b) > y:
                    yMin = -c/abs(b)
            elif yMax < c/abs(b) < y:
                yMax = c/abs(b)
        # vertical
        if b == 0:
            if a > 0:
                if xMin > -c/abs(a) > x:
                    xMin = -c/abs(a)
            elif xMax < c/abs(a) < x:
                xMax = c/abs(a)

    if xMin <= xMax or yMin <= yMax:
        print("NO")
    else:
        if max(xMin, yMin) == float('inf') or min(xMax, yMax) == float('-inf'):
            print("NO")
        else:
            print("YES")
            print((xMax - xMin) * (yMax - yMin))