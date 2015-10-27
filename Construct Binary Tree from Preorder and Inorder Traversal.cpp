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
     TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		int preid = 0;
		return buildTreeUtil(preorder, preid, inorder, 0, inorder.size()-1);
    }
	TreeNode *buildTreeUtil(vector<int> &preorder, int &preid, vector<int> &inorder, int l, int r){
		if(l>r)return NULL;
		if(preid >= preorder.size())return NULL;
		if(l==r){
			preid++;
			return new TreeNode(inorder[l]);
		}
		TreeNode *root = new TreeNode(preorder[preid]);
		int i;
		for(i=l;i<=r;i++){
			if(inorder[i] == preorder[preid]){
			    preid++;
				break;
			}
		}
		root->left = buildTreeUtil(preorder, preid, inorder, l, i-1);
		root->right = buildTreeUtil(preorder, preid, inorder, i+1, r);
		return root;
	}
};