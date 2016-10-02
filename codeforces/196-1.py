n,m = map(int,raw_input().split())
data = map(int,raw_input().split())
data.sort()
answer = 1000000
for x in xrange(0,m-n+1):
	if data[x+n-1]-data[x] < answer:
		answer = data[x+n-1]-data[x] 
print answer