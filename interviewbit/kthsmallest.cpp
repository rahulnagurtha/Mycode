/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int ans;

int recurse(TreeNode *tmp,int target,int prev) {
	if(tmp == NULL) return 0;
	int lftNodes = 0;
	int rightNodes = 0;
	lftNodes = recurse(tmp->left,target,prev);
	if(lftNodes + 1 + prev == target) ans = tmp->val;
	rightNodes = recurse(tmp->right,target,prev + lftNodes + 1);
	return lftNodes + rightNodes + 1;
}

int Solution::kthsmallest(TreeNode* root, int k) {
	ans = -1;
	recurse(root,k,0);
	return ans;
}