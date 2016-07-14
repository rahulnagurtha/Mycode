class Solution:
    # @param A : unsigned integer
    # @return an unsigned integer
    def reverse(self, A):
    	a = bin(A)[2:]
    	while len(a) < 32:
    		a = '0' + a
    	rev = ''.join([a[len(a) - count] for count in xrange(1,len(a)+1)])
    	return int(rev,2)