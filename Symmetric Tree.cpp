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
     bool isSymmetric(TreeNode *root) {
        //return isSymmetricIteratively(root);
		return isSymmetricRecrusive(root);
	}

	bool isSymmetricRecrusive(TreeNode *root){
		if(!root || (!root->left && !root->right))return true;
		bool is = true;
		isSymmetricRecrusiveUtil(root->left,root->right, is);
		return is;
	}
	void isSymmetricRecrusiveUtil(TreeNode *left, TreeNode *right, bool &is){
		if(!is)return;
		if(!left && !right)return;
		if(!left || !right || left->val!=right->val){
			is = false;
			return;
		}
		isSymmetricRecrusiveUtil(left->right, right->left, is);
		isSymmetricRecrusiveUtil(left->left,right->right, is);
	}

	bool isSymmetricIteratively(TreeNode *root){
		if(!root || (!root->left && !root->right))return true;
		queue<TreeNode *> left;
		queue<TreeNode *> right;
		left.push(root->left);
		right.push(root->right);
		TreeNode *curLeft, *curRight;
		while(!left.empty() && !right.empty()){
			curLeft = left.front();
			left.pop();
			curRight = right.front();
			right.pop();
			if(!curLeft && !curRight)continue;
			if(!curLeft || !curRight || curLeft->val != curRight->val)return false;
			left.push(curLeft->right);
			left.push(curLeft->left);
			right.push(curRight->left);
			right.push(curRight->right);
		}
		if(left.size()==0 && right.size()==0)return true;
		return false;
	}
};