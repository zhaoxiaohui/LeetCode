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
    bool hasPathSum(TreeNode *root, int sum) {
        bool find = false;
		hasPathSumUtil(find, root, 0, sum);
		return find;
    }
	void hasPathSumUtil(bool &find, TreeNode *node, int cursum,int sum){
		if(find)return;
		if(!node)return;
		if(!node->left && !node->right && cursum+node->val == sum){
			find = true;
			return;
		}
		if(node->left)hasPathSumUtil(find, node->left, cursum+node->val, sum);
		if(node->right)hasPathSumUtil(find, node->right, cursum+node->val, sum);
	}
};