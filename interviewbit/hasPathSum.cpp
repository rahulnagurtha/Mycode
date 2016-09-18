/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool isThereAPath;
vector<int> T;

void check(TreeNode* tmp, int curSum, int targetSum) {
	if(tmp == NULL) return;
	T.push_back(tmp->val);
	curSum += tmp->val;
	if(tmp->left == NULL && tmp->right == NULL) {
		if(curSum == targetSum) isThereAPath = true;
	}
	if(tmp->left != NULL) check(tmp->left,curSum,targetSum);
	if(tmp->right != NULL) check(tmp->right,curSum,targetSum);
	T.pop_back();
	return;
}

int Solution::hasPathSum(TreeNode* A, int B) {
	isThereAPath = false;
	T.clear();
	check(A,0,B);
	if(isThereAPath) return 1;
	else return 0;
}