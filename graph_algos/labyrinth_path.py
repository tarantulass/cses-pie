from collections import deque

r,c = map(int, input().split())
grid = [input() for i in range(r)]
verdict = False
vis = [[0 for i in range(c)] for i in range(r)]
#verdict AND path both needed !!!
# till now used verdict but path other than tracer no clue!!
# need to use some kind of Djikstra
# need a vis grid also
# no need of shortest path only the verdict is important

# previous was only for verdict but bfs parent trackign actually gives us the verdict and shortest path both

parent = {}

A_pos = None
B_pos = None

for i in range(r):
    for j in range(c):
        if grid[i][j] == 'A':
            A_pos = (i, j)
        if grid[i][j] == 'B':
            B_pos = (i, j)

queue = deque()
queue.append(A_pos)
vis[A_pos[0]][A_pos[1]] = 1
parent[A_pos] = None

found = False
while queue:
    row, col = queue.popleft()
    if (row, col) == B_pos:
        found = True
        break
    for (nr, nc, direction) in [(row+1,col,'D'),(row-1,col,'U'),(row,col+1,'R'),(row,col-1,'L')]:
        if 0<=nr<r and 0<=nc<c and vis[nr][nc]==0 and grid[nr][nc]!='#':
            vis[nr][nc] = 1
            parent[(nr,nc)] = (row, col)  # written ONCE never overwritten
            queue.append((nr,nc))

if not found:
    print("NO")
else:
    # traceback
    path = []
    cell = B_pos
    while cell != A_pos:
        prev = parent[cell]
        pr, pc = prev
        cr, cc = cell
        if cr == pr+1: path.append('D')
        elif cr == pr-1: path.append('U')
        elif cc == pc+1: path.append('R')
        elif cc == pc-1: path.append('L')
        cell = prev
    path.reverse()
    print("YES")
    print(len(path))
    print(''.join(path))
