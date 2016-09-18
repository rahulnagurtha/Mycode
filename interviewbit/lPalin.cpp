/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

typedef pair<ListNode*,ListNode*> PNN;

PNN recurse(ListNode *front,int k) {
	assert(k > 0);
	if(k == 1) return make_pair(front,front);
	PNN rytList;
	rytList = recurse(front->next,k - 1);
	front->next = rytList.second->next;
	rytList.second->next = front;
	return make_pair(rytList.first,front);
}

int Solution::lPalin(ListNode* A) {
	int cnt = 0;
	if(A == NULL || A->next == NULL) return 1;
	ListNode *tmp = A;
	while(tmp != NULL) {
		cnt++;
		tmp = tmp->next;
	}
	PNN firstHalf;
	ListNode *ptrOne,*ptrTwo;
	firstHalf = recurse(A,cnt/2);
	ptrOne = firstHalf.first;
	ptrTwo = firstHalf.second->next;
	if(cnt%2 != 0) ptrTwo = ptrTwo->next;
	while(ptrTwo != NULL) {
		if(ptrTwo->val != ptrOne->val) return 0;
		ptrOne = ptrOne->next;
		ptrTwo = ptrTwo->next;
	}
	return 1;
}