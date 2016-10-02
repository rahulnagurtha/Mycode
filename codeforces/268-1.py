n = input()
one = raw_input().split()
two = raw_input().split()
mergedlist = list(set(one[1:] + two[1:]))
if len(mergedlist) == n:
	print 'I become the guy.'
else:
	print 'Oh, my keyboard!'