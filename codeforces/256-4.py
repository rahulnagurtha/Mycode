n,m,k = map(int,raw_input().split())
a = []
maxsize = len(str(n*m))
for x in xrange(1,n+1):
	for y in xrange(1,m+1):
		a.append((str(x*y)).zfill(maxsize))
a.sort()
# print a
print int(a[k-1])