n = int(raw_input())
p =  map(int, raw_input().split())
possible = True
for x in xrange(0,n):
	ln = raw_input().split(' ')
	cnt = 0
	for y in ln:
		for z in y:
			if z in ['a','e','i','o','u','y']:
				cnt += 1
	if cnt != int(p[x]):
		possible = False
if possible:
	print 'YES'
else:
	print 'NO'