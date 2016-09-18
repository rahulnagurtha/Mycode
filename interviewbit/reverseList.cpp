/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

pair<ListNode*,ListNode*> recurse(ListNode *start) {
	if(start->next == NULL) return make_pair(start,start);
	pair<ListNode*,ListNode*> ret = recurse(start->next);
	ret.second->next = start;
	start->next = NULL;
	return make_pair(ret.first,start);
}

ListNode* Solution::reverseList(ListNode* A) {
    return (A == NULL ? A : reverseList(A).first);
}