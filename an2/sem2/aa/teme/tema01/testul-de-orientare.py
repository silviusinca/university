class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def calc_determinant(P, Q, R):
    return Q.x*R.y + P.x*Q.y + R.x*P.y - Q.x*P.y - R.x*Q.y - P.x*R.y

t = int(input())

for i in range(t):
    nums = [int(x) for x in input().split()]
    P = Point(nums[0], nums[1])
    Q = Point(nums[2], nums[3])
    R = Point(nums[4], nums[5])

    determinant = calc_determinant(P, Q, R)

    if determinant == 0:
        print("TOUCH")
    elif determinant < 0:
        print("RIGHT")
    else:
        print("LEFT")
