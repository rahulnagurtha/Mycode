p = 1
def f(x):
	global p
	p += 1
	return (x,p-1)

n,k = map(int,raw_input().split())
inp = map(int,raw_input().split())
inp = map(f,inp)
inp.sort(key = lambda x:x[0])

ind = 0
for x in inp:
	if k >= x[0]:
		k -= x[0]
		ind += 1
	else:
		break
print ind
for x in xrange(0,ind):
	print inp[x][1],