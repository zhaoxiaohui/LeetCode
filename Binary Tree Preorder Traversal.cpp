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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;

		if(root){
			res.push_back(root->val);
			vector<int> left = preorderTraversal(root->left);
			vector<int> right = preorderTraversal(root->right);
			for(int i=0;i<left.size();i++)
				res.push_back(left[i]);
			for(int i=0;i<right.size();i++)
				res.push_back(right[i]);

		}
		return res;
    }
};