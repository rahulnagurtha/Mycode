/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void addNode(ListNode *cur,ListNode ** head,ListNode **tail) {
    if(*head == NULL) {
        *head = cur;
        *tail = cur;
    }
    else {
        (*tail)->next = cur;
        *tail = (*tail)->next;
    }
    (*tail)->next = NULL;
    return;
}


ListNode* reverseList(ListNode *head) {
    ListNode *cur,*prev = NULL,*Next;
    cur = head;
    while(cur != NULL) {
        Next = cur->next;
        head = cur;
        head->next = prev;
        prev = head;
        cur = Next;
    }
    return head;
}

ListNode* Solution::reorderList(ListNode* A) {
    int lenA = 0;
    ListNode *ptr = A;
    ListNode *headNode = NULL,*extraNode = NULL;
    ListNode *tailNode = NULL;
    ListNode *ptr1,*ptr2;
    ListNode *tmp1,*tmp2;
    while(ptr != NULL) {
        lenA++;
        ptr = ptr->next;
    }
    if(lenA <= 2) return A;
    int til = (1 + lenA)/2;
    ptr = A;
    for (int i = 1; i < til; ++i) {
        ptr = ptr->next;
    }
    if(lenA%2 != 0) extraNode = ptr;
    ptr1 = A;
    ptr2 = reverseList(ptr->next);
    while(ptr2 != NULL) {
        tmp1 = ptr1;
        tmp2 = ptr2;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        addNode(tmp1,&headNode,&tailNode);
        addNode(tmp2,&headNode,&tailNode);
    }
    if(extraNode != NULL) addNode(extraNode,&headNode,&tailNode);
    return headNode;
}