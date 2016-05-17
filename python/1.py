a = 1
b = 2
fib = []
fib.append(a)
while b <= 1000000000:
	fib.append(b)
	tmp = b
	b = b + a
	a = tmp

mem = {}


def num(target,till,chances):
	if (target,till,chances) in mem:
		return mem[(target,till,chances)]
	ans = 0
	if target == fib[till]:
		if chances == 1:
			ans += 1
		if till > 0:
			ans += num(target,till-1,chances)
	elif target - fib[till] < 0:
		if till > 0:
			ans += num(target,till-1,chances)
	else:
		if chances > 1:
			ans += num(target - fib[till],till,chances-1)
		if till > 0:
			ans += num(target,till-1,chances)
	ans = ans % 1000000007
	mem[(target,till,chances)] = ans
	return ans

q = input()
for x in xrange(0,q):
	x , k = map(int,raw_input().split())
	print num(x,len(fib)-1,k)