n = len(weights)
dp = [
    [0] * (W + 1) for _ in range(n + 1)
]
for i in range(n + 1):
    for w in range(W + 1):
        if i == 0 or w == 0: dp[i][w] = 0
        elif weights[i-1] <= w: dp[i][w] = max(values[i-1] + dp[i-1][w - weights[i-1]], dp[i-1][w])
        else: dp[i][w] = dp[i-1][w]
    print("Random Print")
return dp[n][W]