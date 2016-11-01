/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    stack<TreeNode *> T;
    vector<int> ans;
    T.push(A);
    while(!T.empty()) {
    	if(T.top() == NULL) {
    		T.pop();
    		continue;
    	}
    	TreeNode *cur;
    	cur = T.top();
    	T.pop();
    	ans.push_back(cur->val);
    	T.push(cur->right);
    	T.push(cur->left);
    }
    return ans;
}