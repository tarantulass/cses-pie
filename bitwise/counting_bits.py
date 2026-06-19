n = int(input())

count,index = 0,1
while index<=n:
	temp = index
	while temp:
		# & gives bitwise 
		temp = temp&(temp-1)
		count+=1
	index+=1

print(count)
