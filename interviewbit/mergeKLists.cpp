/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > Q;
    ListNode *newHead,*newTail;
    newHead = newTail = new ListNode(-1);
    for (int i = 0; i < A.size(); ++i) {
    	if(A[i] != NULL) {
    		Q.push(make_pair(A[i]->val,i));
    		A[i] = A[i]->next;
    	}
    }
    while(!Q.empty()) {
    	pair<int,int> cur;
    	cur = Q.top();
    	Q.pop();
    	newTail->next = new ListNode(cur.first);
    	newTail = newTail->next;
    	if(A[cur.second] != NULL) {
    		Q.push(make_pair(A[cur.second]->val,cur.second));
    		A[cur.second] = A[cur.second]->next;
    	}
    }
    return newHead->next;
}