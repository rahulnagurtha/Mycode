t = input()
for x in xrange(0,t):
	act,origin = raw_input().split()
	act = int(act)
	points = 0
	for y in xrange(0,act):
		tmp = raw_input().split()
		if tmp[0] == "CONTEST_WON":
			points += 300 + max(0,20-int(tmp[1]))
		elif tmp[0] == "TOP_CONTRIBUTOR":
			points += 300
		elif tmp[0] == "BUG_FOUND":
			points += int(tmp[1])
		else:
			points += 50
	if origin == "INDIAN":
		print points/200
	else:
		print points/400
