for x in xrange(1,100):
	print x,
	sumVal = 0;
	tmp = x
	while x > 0:
		sumVal += x
		x /= 10
	print sumVal