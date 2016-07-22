<<<<<<< HEAD
class Solution:
    # @param A : unsigned integer
    # @return an unsigned integer
    def reverse(self, A):
    	a = bin(A)[2:]
    	while len(a) < 32:
    		a = '0' + a
    	rev = ''.join([a[len(a) - count] for count in xrange(1,len(a)+1)])
    	return int(rev,2)
=======
a = 1
b = 0


num = [1,0]

for x in xrange(1,15):
	print sum(num),
	newone = []
	for y in range(0,len(num)-1):
		newone.append(num[y])
		newone.append(num[y] + num[y+1])
	newone.append(num[len(num)-1])
	num = newone
				
>>>>>>> ba6df834a55ad4f2b0a1ad8d3c6b4d082c9871b3
