/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */



ListNode* Solution::rotateRight(ListNode* A, int B) {
    if(A == NULL) return A;
    ListNode *ptr = A,*head,*tail;
    int lenA = 0;
    while(ptr != NULL) {
    	lenA++;
    	ptr = ptr->next;
    }
    B = B % lenA;
    if(B == 0) return A;
    ptr = A;
    for (int i = 1; i < (lenA - B); ++i) {
    	ptr = ptr->next;
    }
    tail = ptr;
    head = tail->next;
    ptr = head;
    while(ptr->next != NULL) {
    	ptr = ptr->next;
    }
    tail->next = NULL;
    ptr->next = A;
    return head;
}