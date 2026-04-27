import sys

def matrix_chain_order(p):
    n = len(p)
    
    # dp[i][j] = minimum cost to multiply matrices i to j
    dp = [[0 for _ in range(n)] for _ in range(n)]

    # l = chain length
    for length in range(2, n):
        for i in range(1, n - length + 1):
            j = i + length - 1
            dp[i][j] = sys.maxsize

            for k in range(i, j):
                cost = (dp[i][k] +
                        dp[k+1][j] +
                        p[i-1] * p[k] * p[j])

                dp[i][j] = min(dp[i][j], cost)

    return dp[1][n-1]


# Input
n = int(input("Enter number of dimensions: "))
p = list(map(int, input("Enter dimensions: ").split()))

print("Minimum multiplication cost:", matrix_chain_order(p))