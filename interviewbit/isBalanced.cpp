/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

typedef pair<int,int> PII;

bool isHeightBalanaced;

int check(TreeNode* A) {
	if(A == NULL) return 0;
	int lftHeight = check(A->left);
	int rytHeight = check(A->right);
	if(abs(lftHeight - rytHeight) > 1) isHeightBalanaced = false;
	return 1 + max(lftHeight,rytHeight);
}

int Solution::isBalanced(TreeNode* A) {
    isHeightBalanaced = true;
    check();
    return isHeightBalanaced;
}