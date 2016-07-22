x = raw_input().split('e')
num = x[0].split('.')
if int(num[1]) == 0:
	ans = num[0]
	for x in xrange(0,int(x[1])):
		ans += '0'
	print ans
else:
	ans = num[0]
	if (int(x[1]) >= len(num[1])):
		for y in num[1]:
			ans += y
		for y in xrange(0,int(x[1]) - len(num[1])):
			ans += '0'
	else:
		for y in xrange(0,int(x[1])):
			ans += num[1][y]
		ans += '.'
		for y in xrange(int(x[1]),len(num[1])):
			ans += num[1][y]
	print ans