/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    if(A == NULL) return A;
    vector<int> B;
    ListNode *ptr;
    ptr = A;
    while(ptr != NULL) {
    	B.push_back(ptr->val);
    	ptr = ptr->next;
    }
    sort(B.begin(),B.end());
    ptr = A;
    for (int i = 0; i < B.size(); ++i) {
    	ptr->val = B[i];
    	ptr = ptr->next;
    }
    return A;
}