/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
	if(A == NULL) return A;
	unordered_map<RandomListNode *,RandomListNode *> forWard;
	unordered_map<RandomListNode *,RandomListNode *> backWard;
	RandomListNode *cur = A;
	RandomListNode *newHead,*newTail;
	newHead = newTail = NULL;
	while(cur != NULL) {
		if(newTail == NULL) {
			newHead = new RandomListNode(cur->label);
			newTail = newHead;
		}
		else {
			newTail->next = new RandomListNode(cur->label);
			newTail = newTail->next;
		}
		forWard[cur] = newTail;
		backWard[newTail] = cur;
		cur = cur->next;
	}
	cur = newHead;
	while(cur != NULL) {
		cur->random = (backWard[cur]->random == NULL ? NULL : forWard[backWard[cur]->random]);
		cur = cur->next;
	}
	return newHead;
}
