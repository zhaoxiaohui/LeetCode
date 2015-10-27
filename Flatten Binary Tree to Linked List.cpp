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
    void flatten(TreeNode *root) {
        flattenUtil(root);
    }
	TreeNode *flattenUtil(TreeNode *node){

		if(!node)return NULL;
		TreeNode *left = flattenUtil(node->left);
		TreeNode *right = flattenUtil(node->right);
		if(left && right){
			TreeNode *t = node->right;
			node->right = node->left;
			node->left = NULL;
			left->right = t;
			return right;
		}else if(left){
			node->right = node->left;
			node->left = NULL;
			return left;
		}else if(right){
			return right;
		}
		return node;
	}
};