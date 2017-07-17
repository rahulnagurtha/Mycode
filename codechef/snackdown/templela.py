numCases = input()
for x in xrange(0,numCases):
	n = input()
	a = map(int,raw_input().split(' '))
	l = 0
	r = n - 1
	isValid = ((n % 2) == 1)
	while l < r:
		isValid = (isValid and (a[l] == a[r]))
		l += 1
		r -= 1
	for y in xrange(1,n/2+2):
		isValid = (isValid and (a[y-1] == y))
	if isValid:
		print 'yes'
	else:
		print 'no'