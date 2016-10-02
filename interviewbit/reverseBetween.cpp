/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define PLL pair<ListNode,ListNode>

PLL recurse(ListNode cur,int m,int n) {
	if(m == n) return make_pair(cur,cur);
	PLL tmp = recurse(tmp->next,m+1,n);
	cur->next = tmp.second->next;
	tmp->second->next = cur;
	return make_pair(tmp.first,cur);
}

ListNode* Solution::reverseBetween(ListNode* A, int m, int n) {
	ListNode *last = NULL,*ptr = A;
	int curPos = 1;
	PLL tmp;
	while(ptr != NULL) {
		if(curPos == m) {
			tmp = recurse(ptr,m,n);
			if(last == NULL) return tmp.first;
			last->next = tmp.first;
			return A;
		}
		last = ptr;
		ptr = ptr->next;
		curPos++;
	}
	return NULL;
}