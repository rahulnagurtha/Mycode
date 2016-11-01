/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *dupHead;
    ListNode *tail,*cur = A;
    dupHead = tail = new ListNode(INT_MIN);
    while(cur != NULL) {
    	int curVal = cur->val;
    	bool shouldAdd = true;
		while(cur->next != NULL && cur->next->val == curVal) {
			shouldAdd = false;
			cur = cur->next;
		}
		if(shouldAdd) {
			tail->next = cur;
			tail = tail->next;
		}
		cur = cur->next;
    }
    tail->next = NULL;
    return dupHead->next;
}