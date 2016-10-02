n = raw_input()
a = raw_input().split('W')
sz = 0
for x in a:
	if len(x) > 0:
		sz += 1
print sz
for x in a:
	if len(x) > 0:
		print len(x),