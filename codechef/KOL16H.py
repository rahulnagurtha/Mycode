t = input()
for x in xrange(1,t+1):
	print 'Case '+ str(x) + ':',
	n = input()
	if(n < 33):
		print ((1 << n) - 1) % (1 << 33)
	else:
		print 8589934591 % (1 << 33)