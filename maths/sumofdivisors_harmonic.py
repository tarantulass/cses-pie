n = int(input())

# we jsut find the number of times a number can be included in sum
sumval=0
bignum = 10**9+7
i=1

while i <= n:
	q = n//i
	last = n//q
	sumval+=q*((i+last)*(last - i +1)//2)
	i = last+1

print(sumval%bignum)


