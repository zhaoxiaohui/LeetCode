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
    bool isValidBST(TreeNode *root) {
        bool find = true;
		isValidBSTUtil(root, NULL, NULL, find);
		return find;
    }

	void isValidBSTUtil(TreeNode *node, TreeNode *leftP, TreeNode *rightP, bool &find){
		if(!find)return;
		if(!node || (!node->left && !node->right))return;
		if(node->left){
			if(node->left->val >= node->val || (rightP!=NULL && node->left->val <= node->val && node->left->val <= rightP->val)){
				find = false;
				return;
			}
			isValidBSTUtil(node->left, node, rightP, find);
		}
		if(node->right){
			if(node->right->val <= node->val || (leftP!=NULL && node->right->val >= node->val && node->right->val >= leftP->val)){
				find = false;
				return;
			}
			isValidBSTUtil(node->right, leftP, node, find);
		}
	}
};