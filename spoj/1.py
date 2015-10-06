import math
t=input()
for x in xrange(1,t+1):
	y=input()
	print math.factorial(2*y)/(math.factorial(y)*math.factorial(y))
