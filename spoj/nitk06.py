t = input()

for x in xrange(0,t):
	n = input()
	flag = 0
	inpnum = raw_input().split()
	inp = []
	for y in xrange(0,n):
		inp.append(int(inpnum[y]))
	for y in xrange(0,n-1):
		if(inp[y] < 0):
			flag = 1
		else:
			inp[y+1] = inp[y+1] - inp[y]
	if(inp[n-1] != 0):
		flag = 1
	if flag == 1:
		print 'NO'
	else:
		print 'YES'
		
