/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

typedef vector<int> VI;
typedef vector<VI> VOVI;


VOVI Solution::zigzagLevelOrder(TreeNode* A) {
    VOVI ans;
    VI tmp;
    if(A == NULL) return ans;
    deque<TreeNode *> Q[2];
    int cur = 0;
    Q[0].push_back(A);
    while(!Q[cur].empty()) {
    	tmp.clear();
		while(!Q[cur].empty()) {
			if(Q[cur].front() != NULL) {
				tmp.push_back(Q[cur].front()->val);
				Q[(cur + 1) % 2].push_back(Q[cur].front()->left);
				Q[(cur + 1) % 2].push_back(Q[cur].front()->right);
			}
			Q[cur].pop_front();
		}
		if(cur == 1) reverse(tmp.begin(),tmp.end());
    	if(tmp.size() != 0) ans.push_back(tmp);
    	cur++;
    	cur %= 2;
    }
    return ans;
}