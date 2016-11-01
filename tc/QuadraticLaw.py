class QuadraticLaw:
	def getTime(self, d):
		l = 0
		r = d
		while l < r:
			mid = (l + r + 1)/2
			if mid + mid*mid > d:
				r = mid - 1
			else:
				l = mid
		return l 
