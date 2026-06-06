# always in question like these just apply the standard reducing the problem approach insstead of 4 sum solve 2 sum
# instead of 3 sum solve 2 sum by just getting the 1 fix and keeping other on pointers

n,x = map(int, input().split())
arr = list(map(int, input().split()))
found = False
summap = {}
for i in range(n-1):
	for j in range(i+1, n):
		summap[arr[i] + arr[j]] = (i,j)
		# key is the sum and value is the index
		# yes this solution overwrites the same sum with different index but who cares we only need to print one
for i in range(n-1):
	for j in range(i+1,n):
		leftsum = x - arr[i]-arr[j]
		if leftsum in summap:
			check = i not in summap[leftsum] and j not in summap[leftsum]
			# not above as leftsum may not be in thee yet
			if check:
				k, l = summap[leftsum]
				print(i+1,j+1, k+1, l+1,sep=" ")
				# 1 based indexes to be printed
				found = True
				break
	if found:
		break

if not found:
	print("IMPOSSIBLE")

## important failed at
#4 9
#4 1 2 3

#correct output
#IMPOSSIBLE

#user output
#0 1 1 3
