from collections import deque
n = int(input())

circ = deque(range(1,n+1))
order = []

while circ:
	circ.append(circ.popleft())
	order.append(circ.popleft())

# important best to print all in 1 line just use
print(*order)

