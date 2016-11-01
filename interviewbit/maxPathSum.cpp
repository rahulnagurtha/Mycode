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

int findMaxPath(TreeNode *cur) {
	if(cur == NULL) return 0;
	
	int lft = findMaxPath(cur->left);
	int ryt = findMaxPath(cur->right);

	int endingHere = cur->val + max(0,max(lft,ryt));

	ans = max(ans,cur->val + max(0,lft) + max(0,ryt));
	
	return endingHere;
}

int Solution::maxPathSum(TreeNode* A) {
    ans = INT_MIN;
    findMaxPath(A);
    return ans;
}