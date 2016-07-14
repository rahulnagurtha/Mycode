def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)


for x in xrange(1,10):
	a = input()
	b = input()
	print egcd(a,b)