n = int(input())
# no. of ways one can get n by throwing a dice
# dice can be thrown any no. of times!!
# print the number of ways modulo 10**9+7

# it is indeed the fibonacci's largest brother f(n-i) sum from i = 1 to 6
dp = [0]*(n+1)
dp[1:7] = [2**(i-1) for i in range(1,7)]

sumval = sum(dp[1:7])
index = 7
while index<=n:
	sumval = sumval - dp[index-7]
	dp[index] = sumval%(10**9+7)
	sumval = sumval + dp[index]
	index+=1

print(dp[n]%(10**9+7))
