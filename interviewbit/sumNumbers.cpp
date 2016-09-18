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

void add(TreeNode *tmp,int cur) {
	if(tmp == NULL) return;
	if(tmp->left == NULL && tmp->right == NULL) {
		ans = (ans + cur*10 + tmp->val) % 1003;
		return;
	}
	if(tmp->left != NULL) add(tmp->left,(cur*10 + tmp->val) % 1003);
	if(tmp->right != NULL) add(tmp->right,(cur*10 + tmp->val) % 1003);
	return;
}

int Solution::sumNumbers(TreeNode* A) {
    ans = 0;
	add(A,0);
	return ans % 1003;
}