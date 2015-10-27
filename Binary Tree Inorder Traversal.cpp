/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
		inorderTraversalUtil(root, ret);
		return ret;
    }
	void inorderTraversalUtil(TreeNode *node, vector<int> &ret){
		if(!node)return;
		inorderTraversalUtil(node->left, ret);
		ret.push_back(node->val);
		inorderTraversalUtil(node->right, ret);
	}
};