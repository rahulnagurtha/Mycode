import heapq



# pop top n combinations from A,B
def getLargestN(A,B,n):
	len_A = len(A)
	len_B = len(B)
	Q = []
	answer = []
	A.sort()
	B.sort()
	for x in range(0,len_A):
		Q.append((-1*(A[x] + B[len_B - 1]),(x,len_B - 1)))
	heapq.heapify(Q)
	for i in range(0,n):
		if len(Q) == 0:
			break
		tmp = heapq.heappop(Q)
		answer.append((-1*tmp[0],(A[tmp[1][0]],B[tmp[1][1]])))
		if tmp[1][1] > 0:
			heapq.heappush(Q, (-1*(A[tmp[1][0]] + B[tmp[1][1]-1]),(tmp[1][0],tmp[1][1]-1)))
	return answer

print getLargestN([1,4,2,3],[2,5,1,6], 4)