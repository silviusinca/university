# complexitate - in timp    = O(n*K)
#              - in spatiu  = O(K)

n = int(input())
K = int(input())

S = []
for i in range(n):
    S.append(int(input()))

dp = [0 for i in range(K+1)]
for i in range(n):
    k = K
    while (k >= 0 and k-S[i] >= 0):
        dp[k] = max(dp[k], dp[k-S[i]] + S[i])
        k -= 1

print(dp[K])
