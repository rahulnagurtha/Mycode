/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
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
    	T.push(cur->left);
        T.push(cur->right);
    }
    if(ans.size() > 0) reverse(ans.begin(),ans.end());
    return ans;
}