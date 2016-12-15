a = raw_input()
if a == '{}':
	print '0'
else :
	b = [x.strip() for x in a[1:-1].split(',')]
	c = 0
	print len(set(b))