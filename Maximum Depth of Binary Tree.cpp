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
    int maxDepth(TreeNode *root) {
        if(!root)return 0;
		int ret = 0;
		maxDepthUtil(root, ret, 0);
		return ret;
    }
	void maxDepthUtil(TreeNode *node, int &ret, int deep){
	    if(!node){
			if(ret < deep){
				ret = deep;
			}
			return;
		}
		maxDepthUtil(node->left, ret, deep + 1);
		maxDepthUtil(node->right, ret, deep + 1);
	}
};