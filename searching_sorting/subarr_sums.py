# subarray strcitly mean contiguous

n,x = map(int, input().split())

arr = list(map(int, input().split()))
count=0
left, right = 0,0
sumval = arr[0]
#for i in range(n):
#	arr.append(int(input()))

# b4 rigth<=n it may happen that right keeps on increasing !!
# since array has positive integers!!
while right<n: # make right inclusive
	if sumval==x:
		count+=1
		sumval-=arr[left]
		left+=1
 # to get the next one as it is positive so anything will increase
	elif sumval<x:
		right+=1
		if right==n:
			break
		sumval+=arr[right]
	else:
		sumval-=arr[left]
		left+=1

print(count)
