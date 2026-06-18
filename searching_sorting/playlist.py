n = int(input())
# longest sequence of distinct songs basically character
songs = list(map(int, input().strip().split()))
# as map is not subsriptable!!
# strip removes space split creates string list and finally we have int
map = {}
start,ans = 0,0
# just stoe the prev occurence in the map object
# update the entry index
# so that repeatign wont cause issues!!

for i in range(n):
	if songs[i] not in map:
		map[songs[i]] = i
	else:
		if map[songs[i]]>=start:
			start = map[songs[i]] + 1
		# this defines the window start variable!!
		# updated the new occurence and +1 as we found a duplicate with that !!
		map[songs[i]]=i
	ans = max(ans, i - start + 1)

print(ans)
