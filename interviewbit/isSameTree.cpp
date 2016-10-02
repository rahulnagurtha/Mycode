/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool areIdentical(TreeNode* A, TreeNode* B) {
	if(A == NULL && B == NULL) return true;
	if(A == NULL || B == NULL) return false;
	return ((A->val == B->val) && areIdentical(A->left,B->left) && areIdentical(A->right,B->right));
}

int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    return areIdentical(A,B);
}
