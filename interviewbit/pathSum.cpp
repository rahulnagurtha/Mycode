/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

typedef vector<vector<int> > VOVI;

VOVI ans;
vector<int> T;

void check(TreeNode* tmp, int curSum, int targetSum) {
	if(tmp == NULL) return;
	T.push_back(tmp->val);
	curSum += tmp->val;
	if(tmp->left == NULL && tmp->right == NULL) {
		if(curSum == targetSum) {
			ans.push_back(T);
		}
	}
	if(tmp->left != NULL) check(tmp->left,curSum,targetSum);
	if(tmp->right != NULL) check(tmp->right,curSum,targetSum);
	T.pop_back();
	return;
}

vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) {
	ans.clear();
	T.clear();
	check(root,0,sum);
	return ans;
}