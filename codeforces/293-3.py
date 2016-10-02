ans = 0
fact = {}
ans = 0
originalVal = 1
largest = {}


# (originalVal,0,1)
def recurse(cur,ansSoFar,valueSoFar):
	# print cur,ansSoFar,valueSoFar
	global ans
	global originalVal
	if valueSoFar > originalVal:
		return
	if valueSoFar == originalVal:
		ans = max(ans,ansSoFar)
		return
	else :
		for x in xrange(2,10):
			if cur % fact[x] == 0:
				recurse(cur/fact[x],ansSoFar*10 + x,valueSoFar*fact[x])
		return

fact[1] = 1
fact[0] = 1
for x in xrange(2,10):
	fact[x] = fact[x-1]*x
largest[1] = 1
for x in xrange(2,10):
	originalVal = fact[x]
	ans = 0
	recurse(originalVal,0,1)
	largest[x] = ans
	# print largest[x],
# print

n = raw_input()
digitString = raw_input()
digits = list(digitString)

answer = ''

for x in digits:
	if int(x) not in  [0,1]:
		answer += str(largest[int(x)])
print ''.join(sorted(answer))[::-1]