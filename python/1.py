length = 0
for n in xrange(1,1000):
	curLen = 0
	for x in xrange(0 ,n + 1):
		for y in xrange(0 ,n + 1):
			if x**2 + y**2 == n**2:
				curLen += 1
	length = max(length,curLen)

print length