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
    int minDepth(TreeNode *root) {
        int res = 0;
        if(root != NULL){
            if(!root->left)res = 1+findMin(root->right);
            else if(!root->right)res = 1+ findMin(root->left);
            else res = 1 + min(findMin(root->left), findMin(root->right));
            //res = 1+min(findMin(root->left),findMin(root->right));
        }
        return res;
    }
    int findMin(TreeNode *node){
        if(node){
           if(!node->left)return 1+findMin(node->right);
            else if(!node->right)return 1+ findMin(node->left);
            else return 1 + min(findMin(node->left), findMin(node->right));
        }else return 0;
    }
};