/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
	ListNode *ptr,*tmp;
	ListNode *lowerHead,*lowerTail;
	ListNode *higherHead,*higherTail;
	*lowerHead = *lowerTail = *higherHead = *higherTail = NULL;
	ptr = A;
	while(ptr != NULL) {
		tmp = ptr;
		ptr = ptr->next;
		if(tmp->val < B) {
			if(lowerHead == NULL) lowerHead = lowerTail = tmp;
			else {
				lowerTail->next = tmp;
				lowerTail = lowerTail->next;
			}
		}
		else {
			if(higherHead == NULL) higherHead = higherTail = tmp;
			else {
				higherTail->next = tmp;
				higherTail = higherTail->next;
			}
		}
	}
	if(higherHead == NULL) return lowerHead;
	if(lowerHead == NULL) return higherHead;
	lowerTail->next = higherHead;
	higherTail->next = NULL;
	return lowerHead;
}