/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool isReverse(TreeNode *A, TreeNode *B) {
	if(A == NULL && B == NULL) return true;
	if(A == NULL || B == NULL) return false;
	return ((A->val == B->val) && isReverse(A->left,B->right) && isReverse(A->right,B->left));
}

int Solution::isSymmetric(TreeNode* A) {
	if(A == NULL) return true;
	return isReverse(A->left,A->right);
}