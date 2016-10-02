import math,string,itertools,collections

def test(a,b):
	if len(a) >= len(b):
		if b in a:
			return a
		else:
			for x in xrange(0,len(b)):
				if b[0:len(b)-x] == a[len(a)-len(b)+x:len(a)]:
					return a+b[len(b)-x:]
	else:
		for x in xrange(0,len(a)):
			if b[0:len(a)-x] == a[x:len(a)]:
				return a[:] + b[len(a)-x:]
	return a + b

class FourStrings:
	def shortestLength(self,a,b,c,d):
		ans = 50
		for x in list(itertools.permutations([a,b,c,d])):
			ans = min(len(reduce(test,x)),ans)
		return ans




p = FourStrings()

w,x,y,z = map(str,raw_input().split())

print w,x,y,z

print p.shortestLength(w,x,y,z)