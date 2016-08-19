class Solution:
    # @param A : string
    # @return an integer
    def lengthOfLastWord(self, A):
    	tmp = A.split()
    	if(len(tmp) == 0):
    	    return 0
    	return len(tmp[-1])