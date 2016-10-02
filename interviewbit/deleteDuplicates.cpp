/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
	ListNode *cur,*previous,*head,*tmp;
	head = A;
	previous = head;
	if(previous != NULL) cur = previous->next;
	while(cur != NULL) {
		if(cur->val == previous->val) {
			tmp = cur;
			previous->next = cur->next;
			cur = cur->next;
			free(tmp);
		}
		else {
			previous = cur;
			cur = cur->next;
		}
	}
	return head;
}