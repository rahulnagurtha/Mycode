#include <bits/stdc++.h>

using namespace std;



struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    int lenA = 0;
    int lenB = 0;
    ListNode *ptr = A;
    ListNode *ptrA,*ptrB;
    while(ptr != NULL) {
    	lenA++;
    	ptr = ptr->next;
    }
    ptr = B;
    while(ptr != NULL) {
    	lenB++;
    	ptr = ptr->next;
    }
    ptrA = A;
    ptrB = B;
    while(lenA > lenB) {
    	lenA--;
    	ptrA = ptrA->next;
    }
    while(lenA < lenB) {
    	lenB--;
    	ptrB = ptrB->next;
    }
    while(ptrA != ptrB) {
    	ptrA = ptrA->next;
    	ptrB = ptrB->next;
    }
    return ptrA;
}



int main()
{
    int t;
    freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {

    }
    return 0;
}