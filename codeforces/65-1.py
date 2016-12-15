n = map(int,raw_input().split())[0]
for x in xrange(0,n):
	a = raw_input()
	if len(a) > 10:
		print a[0] + str(len(a)-2) + a[-1]
	else:
		print a