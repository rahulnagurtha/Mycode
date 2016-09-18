/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
	stack<int> T;
	ListNode *ptrA = A,*ptrB = B;
	ListNode *head = NULL;
	int carry = 0;
	int one,two;
	while(ptrA != NULL || ptrB != NULL || carry > 0) {
		if(ptrA != NULL) {
			one = ptrA->val;
			ptrA = ptrA->next;
		}
		else one = 0;
		if(ptrB != NULL) {
			two = ptrB->val;
			ptrB = ptrB->next;
		}
		else two = 0;
		T.push((one+two+carry)%10);
		carry = (one+two+carry)/10;
	}
	while(!T.empty() && T.top() == 0) {
		T.pop();
	}
	while(!T.empty()) {
		ListNode *tmp = new ListNode(T.top());
		tmp->next = head;
		head = tmp;
		T.pop();
	}
	return head;
}