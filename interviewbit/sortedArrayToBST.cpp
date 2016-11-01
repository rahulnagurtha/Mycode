/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* recurse(const vector<int> &A,int l,int r) {
	if(l > r) return NULL;
	int mid = (l + r)/2;
	TreeNode *cur = new TreeNode(A[mid]);
	cur->left = recurse(A,l,mid-1);
	cur->right = recurse(A,mid+1,r);
	return cur;
}


TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return recurse(A,0,A.size() - 1);
}