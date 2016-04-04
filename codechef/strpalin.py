import string
t = int(raw_input().split()[0])
for t in xrange(t):
	pass
	a = raw_input()
	b = raw_input()
	if len(['a' for x in list(string.ascii_lowercase) if x in a and x in b]) > 0:
		print 'Yes'
	else:
		print 'No'