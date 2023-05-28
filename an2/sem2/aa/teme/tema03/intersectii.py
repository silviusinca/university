minX = minY = float('inf')
maxX = maxY = float('-inf')

el = None

n = int(input())
for i in range(n):
    a, b, c = [int(x) for x in input().split()]

    # orizontal
    if a == 0:
        el = -c / b
        if b < 0:
            maxY = max(maxY, el)
        else:
            minY = min(minY, el)
    # vertical
    elif b == 0:
        el = -c / a
        if a < 0:
            maxX = max(maxX, el)
        else:
            minX = min(minX, el)

if minX == float('inf') or minY == float('inf') or maxX == float('-inf') or maxY == float('-inf'):
    if minX < maxX or minY < maxY:
        print("VOID")
    else:
        print("UNBOUNDED")
elif minX >= maxX and minY >= maxY:
    print("BOUNDED")
elif minX < maxX or minY < maxY:
    print("VOID")
else:
    print("UNBOUNDED")
