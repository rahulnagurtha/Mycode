n = input()
answer = 0
for x in xrange(0,n):
	inp = raw_input().split()
	if inp.count("1") >= 2:
		answer += 1
print answer