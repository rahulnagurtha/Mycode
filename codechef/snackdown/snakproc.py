numCases = input()
for x in xrange(0,numCases):
	n = input()
	src = raw_input()
	src = src.replace(".","")
	isValid = ((len(src) % 2) == 0)
	for y in xrange(0,len(src)):
		if y%2 == 0:
			isValid = (isValid and (src[y] == 'H'))
		else:
			isValid = (isValid and (src[y] == 'T'))
	if isValid:
		print 'Valid'
	else:
		print 'Invalid'