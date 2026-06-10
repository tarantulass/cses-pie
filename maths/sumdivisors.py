import math
n = int(input())

# we have root n algo we simply use it second naive algo not useful
sumval = 0
bignum = (10**9+7)

for k in range(1,n+1):
	num=1
	while num<=math.sqrt(k):
		if k%num==0:
			sumval+=num
			if num**2!=k:
				sumval+=(k//num)
		num+=1
#	print(sumval)

print(sumval%bignum)
