import time
import sys

def function(y):
	for x in xrange(1,y):
		z = 1

counter = 0
lastfew = []

for x in xrange(1,100):
	print "the last few times are :",
	print lastfew
	print "enter a number : "
	parameter = input()
	start_time = time.time()
	function(parameter)
	total = time.time() - start_time
	if counter >= 5:
		if int(total - lastfew[0]) < 60:
			sys.exit(0)
		else:
			y = lastfew.pop(0)
			lastfew.append(total + lastfew[-1])
	else:
		try:
			toappend = lastfew[-1] + total
		except:
			toappend = total
		lastfew.append(toappend)
		counter += 1