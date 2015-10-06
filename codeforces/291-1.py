inp = map(int,list(raw_input()))
final = map(lambda x: min(x,9-x),inp)
sm = 0
for x in final:
	sm += x
flag = 0
toprint = []
if sm == 0:
	print '9'
else :
	for x in final:
		if flag == 0 and x == 0:
			toprint.append(9)
		elif flag == 0 and x != 0:
			flag = 1
			toprint.append(x)
		else:
			toprint.append(x)
	toprint = map(str,toprint)
	toprint = "".join(toprint)
	print toprint
