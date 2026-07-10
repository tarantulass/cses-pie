r,c = map(int, input().split())
grid = [input() for i in range(r)]
verdict = False
vis = [[0 for i in range(c)] for i in range(r)]
#verdict AND path both needed !!!
# till now used verdict but path other than tracer no clue!!
# need to use some kind of Djikstra
# need a vis grid also
# no need of shortest path only the verdict is important

def dfs(row, col, vis):
	# important not and !!!
	if row not in range(r) or col not in range(c):
		return False
	if grid[row][col]=='B':
		return True
	elif grid[row][col]=='#':
		return False
	if vis[row][col]==0:
		vis[row][col] = 1

		path1 = (row+1,col)
		path2 = (row-1,col)
		path3 = (row, col+1)
		path4 = (row, col-1)

		return (dfs(*path1) or dfs(*path2) or dfs(*path3) or dfs(*path4))
	else:
		return False #since already visited but no path

# we only call dfs from A hence no need to reinitilze it again and again
for i in range(r):
	for j in range(c):
		if grid[i][j]=='A':
			verdict = dfs(i,j, vis)

print(verdict)
# this is only for verdict
