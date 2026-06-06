# defaultdict takes an extra overhead
from collections import defaultdict
n,x = map(int, input().split())

arr = list(map(int, input().split()))
count =0
prevmap = defaultdict(int) # important otherwise with no factory type give various errors
cumsum = 0
prevmap[0]=1
# wrong idea
#cumsum = [sum(arr[:i]) for i in range(1,n+1)]
# idea is that we will have a defaultdict such that

#for i in range(n):
#	sum+=arr[i]
#	cumsum[i] = sum

#for i in cumsum:
#	prevmap[i]+=1

#for i in range(n):
#	for j in range(i):
#		if cumsum[i]-cumsum[j]==x:
#			count+=prevmap[cumsum[j]]
# above code created nsquared redundancy use of in for dictionary makes it O(1) like hashmap
# create on the go !!
for i in range(n):
	cumsum+=arr[i]

#	if x-cumsum[i] in prevmap:
# cumsum[j] - cumsum[i] = x
	count+=prevmap[cumsum-x]
	prevmap[cumsum]+=1
	# we only want indices before i not even i also
print(count)


# wrong code logic even when corrected takes O(n^2logn)
#sortarr = None # just for binary search
#cumsum = [0]*n
#sum = 0
# cumsum done
#for i in range(len(arr)):
#	sum += arr[i]
#	cumsum[i] = sum

# now searching target x!
#def bsrch(l, r, x, sortarr):
#	while l<=r:
#		mid = (l+r)//2

#		if sortarr[mid]==x:
#			return True
#		elif sortarr[mid]<x:
#			l = mid+1
#		else:
#			r = mid-1
#	return  False
#
#for i in range(n):
#	sortarr = sorted(arr)
#	count+=(bsrch(i,n,x, sortarr)) # clearly we know other will be 0
#
#	arr = [j-arr[i] for j in arr]
