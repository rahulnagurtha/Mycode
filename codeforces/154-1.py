n,m = map(int,raw_input().split())
a = ['B','G']
answer = []
if n > m:
	for x in xrange(0,2*m):
		answer.append(a[x%2])
	for x in xrange(2*m,n+m):
		answer.append('B')
else:
	for x in xrange(0,2*n):
		answer.append(a[(1+x)%2])
	for x in xrange(2*n,n+m):
		answer.append('G')
answer = "".join(answer)
print answer