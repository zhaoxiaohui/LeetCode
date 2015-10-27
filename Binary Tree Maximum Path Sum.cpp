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
    int maxPathSum(TreeNode *root) {
        int ret = INT_MIN;
		maxPathSum(root, ret);
		return ret;
    }

	void maxPathSum(TreeNode *node, int &ret){
		if(!node)return;
		//leaf
		if(!node->left && !node->right){
			if(ret < node->val){
				ret = node->val;
			}
			return;
		}
		if(node->left)maxPathSum(node->left, ret);
		if(node->right)maxPathSum(node->right, ret);
		if(node->left && node->right){
			if(node->left->val>node->right->val){
				node->val = max(node->val, node->val+node->left->val);
				ret = max(ret, max(node->val, node->val+node->right->val));
			}else{
				node->val = max(node->val, node->val+node->right->val);
				ret = max(ret, max(node->val, node->val+node->left->val));
			}
		}else if(node->left){
			node->val = max(node->val, node->val+node->left->val);
			ret = max(ret, node->val);
		}else{
			node->val = max(node->val, node->val+node->right->val);
			ret = max(ret, node->val);
		}
	}
};