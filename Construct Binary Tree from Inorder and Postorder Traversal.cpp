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
   TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		if(inorder.size() == 0)return NULL;
		int num = postorder.size()-1;
        return buildTreeUtil(inorder, 0, inorder.size()-1, postorder, num);
    }

	TreeNode *buildTreeUtil(vector<int> &inorder, int l, int r, vector<int> &postorder, int &num){
		if(num<0 || l>r)return NULL;
		if(l==r){
			TreeNode *newNode = new TreeNode(postorder[num]);
			num--;
			return newNode;
		}
		for(int i=l;i<=r;i++){
			if(inorder[i] == postorder[num]){
				TreeNode *root = new TreeNode(postorder[num]);
				num--;
				root->right = buildTreeUtil(inorder,i+1, r, postorder, num);
				root->left = buildTreeUtil(inorder, l, i-1, postorder, num);
				return root;
			}
		}
	}
};