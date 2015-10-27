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
    int sumNumbers(TreeNode *root) {
        int sum = 0;
		sumNumbersUitl(root, 0, sum);
		return sum;
    }
	void sumNumbersUitl(TreeNode *node,int curNum, int &sum){
		if(!node)return;
		int curValue = curNum*10 + node->val;
		//leaf
		if(!node->left && !node->right){
			sum += curValue;
			return;
		}
		if(node->left){
			sumNumbersUitl(node->left, curValue, sum);
		}
		if(node->right){
			sumNumbersUitl(node->right, curValue, sum);
		}
	}
};