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
     bool isBalanced(TreeNode *root) {
        bool bal = true;
		isBalancedUtil(root, bal);
		return bal;
    }

	int isBalancedUtil(TreeNode *node, bool &bal){
		if(!node)return 0;
		if(!bal)return -1;
		if(!node->left && !node->right)return 1;
		int left = isBalancedUtil(node->left, bal);
		int right = isBalancedUtil(node->right, bal);
		if(abs(left-right)>1){
			bal = false;
			return -1;
		}
		return max(left, right)+1;
	}
};