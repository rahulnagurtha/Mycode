def Mexp(exp = 0):
	ans = 1
	base = 2
	while exp > 0:
		if(exp % 2 == 1) :
			ans *= base
			ans %= 1000000007
		base *= base
		base %= 1000000007
		exp /= 2
	print ans


t = int(raw_input())
while t > 0:
	n = int(raw_input())
	Mexp(n-1)
	t -= 1