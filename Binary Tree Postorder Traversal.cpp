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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
		if(root == NULL)return res;
		vector<int> left, right;
		if(root->left)left = postorderTraversal(root->left);
		if(root->right)right = postorderTraversal(root->right);
		if(left.size() > 0){
			for(int i=0;i<left.size();i++)
				res.push_back(left.at(i));
		}
		if(right.size() > 0){
			for(int i=0;i<right.size();i++)
				res.push_back(right.at(i));
		}
		res.push_back(root->val);
		return res;
    }
};