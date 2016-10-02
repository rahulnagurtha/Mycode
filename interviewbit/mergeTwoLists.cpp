/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
	ListNode *newHead,*last,*ptrOne,*ptrTwo,*toBeAdded;
	last = newHead = NULL;
	ptrOne = A;
	ptrTwo = B;
	while(A != NULL || B != NULL) {
		if(A != NULL && B != NULL) {
			if(A->val <= B->val) {
				toBeAdded = A;
				A = A->next;
			}
			else {
				toBeAdded = B;
				B = B->next;
			}
		}
		else if(A == NULL) {
			toBeAdded = B;
			B = B->next;
		}
		else {
			toBeAdded = A;
			A = A->next;
		}
		if(newHead == NULL) newHead = toBeAdded;
		if(last != NULL) last->next = toBeAdded;
		last = toBeAdded;
		last->next = NULL;
	}
	return newHead;
}