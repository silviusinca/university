# problema 1
"""
n = int(input("n = "))
k = 0

while n & 1 == 0:
    k += 1
    n = n >> 1

if n == 1:
    n = n << k
    print(f"Numarul {n} este 2^{k}")
else:
    n = n << k
    print(f"Numarul {n} nu este o putere a lui 2")

# SAU
import math

n = int(input("n = "))
k = int(math.log2(n))
if n & (n - 1) == 1:
    print(f"Numarul {n} este 2^{k}")
else:
    print(f"Numarul {n} nu este o putere a lui 2")

"""

# problema 3
""""
n = int(input("n = "))
k = 0
print(f"Reprezentarea binara a numarului {n} este {bin(n)}")

while n != 0:
    if n & 1 == 1:
        k += 1
    n = n >> 1

print(f"Numarul de biti nenuli este {k}")
"""
