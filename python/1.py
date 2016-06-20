a = 1
b = 0


num = [1,0]

for x in xrange(1,15):
	print sum(num),
	newone = []
	for y in range(0,len(num)-1):
		newone.append(num[y])
		newone.append(num[y] + num[y+1])
	newone.append(num[len(num)-1])
	num = newone
				