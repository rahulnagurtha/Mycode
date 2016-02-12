import math

x , y , z = map(float,raw_input().split())

a = ["x^y^z", "x^z^y", "(x^y)^z", "(x^z)^y", "y^x^z", "y^z^x", "(y^x)^z", "(y^z)^x", "z^x^y", "z^y^x", "(z^x)^y", "(z^y)^x"]

idx = 0
tmp = 0


print z*math.log(y)+math.log(math.log(x))
if z*math.log(y)+math.log(math.log(x)) > tmp:
	tmp = z*math.log(y)+math.log(math.log(x))
	idx = 0
print y*math.log(z)+math.log(math.log(x))
if y*math.log(z)+math.log(math.log(x)) > tmp:
	tmp = y*math.log(z)+math.log(math.log(x))
	idx = 1
print math.log(y*z)+math.log(math.log(x))
if math.log(y*z)+math.log(math.log(x)) > tmp:
	tmp = math.log(y*z)+math.log(math.log(x))
	idx = 2





print z*math.log(x)+math.log(math.log(y))
if z*math.log(x)+math.log(math.log(y)) > tmp:
	tmp = z*math.log(x)+math.log(math.log(y))
	idx = 4
print x*math.log(z)+math.log(math.log(y))
if x*math.log(z)+math.log(math.log(y)) > tmp:
	tmp = x*math.log(z)+math.log(math.log(y))
	idx = 5
print math.log(x*z)+math.log(math.log(y))
if math.log(x*z)+math.log(math.log(y)) > tmp:
	tmp = math.log(x*z)+math.log(math.log(y))
	idx = 6





print y*math.log(x)+math.log(math.log(z))
if y*math.log(x)+math.log(math.log(z)) > tmp:
	tmp = y*math.log(x)+math.log(math.log(z))
	idx = 8
print x*math.log(y)+math.log(math.log(z))
if x*math.log(y)+math.log(math.log(z)) > tmp:
	tmp = x*math.log(y)+math.log(math.log(z))
	idx = 9
print math.log(y*x)+math.log(math.log(z))
if math.log(y*x)+math.log(math.log(z)) > tmp:
	tmp = math.log(y*x)+math.log(math.log(z))
	idx = 10


print a[idx]