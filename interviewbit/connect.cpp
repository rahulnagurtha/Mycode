/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

typedef vector<int> VI;
typedef vector<VI> VOVI;

void Solution::connect(TreeLinkNode* A) {
	TreeLinkNode *tmp;
    deque<TreeLinkNode *> Q[2];
    int cur = 0;
    if(A != NULL) Q[0].push_back(A);
    while(!Q[cur].empty()) {
		while(!Q[cur].empty()) {
			tmp = Q[cur].front();
			Q[cur].pop_front();
			if(tmp->left != NULL) Q[(cur + 1) % 2].push_back(tmp->left);
			if(tmp->right != NULL) Q[(cur + 1) % 2].push_back(tmp->right);
			if(!Q[cur].empty()) tmp->next = Q[cur].front();
			else tmp->next = NULL;
		}
    	cur = (cur + 1) % 2;
    }
    return;
}