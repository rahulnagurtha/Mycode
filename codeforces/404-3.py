n , m = map(int,raw_input().split())

if m >= n:
	print n
else:
	l = 0
	r = n
	answer = m
	target = (n - m)*2
	minVal = 0
	while (l <= r):
		mid = (l + r)/2
		if (target <= mid*(mid+1)):
			r = mid - 1
			minVal = mid
		else:
			l = mid + 1
	print answer+minVal