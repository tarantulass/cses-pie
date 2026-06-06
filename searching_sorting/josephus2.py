from collections import deque
n, k = map(int, input().split())

circ = deque(range(1,n+1))
res = []

while circ:
	# since in testcases it may also happen that we have k>n
	for i in range(k%len(circ)):
		circ.append(circ.popleft())

	res.append(circ.popleft())

print(*res)
