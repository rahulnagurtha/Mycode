/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
	ListNode *cur,*previous,*head,*tmp,*lastNode;
	if(A == NULL || A->next == NULL) return A;
	head = A->next;
	lastNode = NULL;
	cur = A;
	while(cur != NULL && cur->next != NULL) {
		previous = cur;
		cur = cur->next;
		tmp = cur->next;
		//swapping
		previous->next = tmp;
		cur->next = previous;
		if(lastNode != NULL) lastNode->next = cur;
		lastNode = previous;
		cur = tmp;
	}
	return head;
}