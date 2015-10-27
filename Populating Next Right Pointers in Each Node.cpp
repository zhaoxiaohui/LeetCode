/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
		if(!root)return;
        connectUtil(root, root->next);
    }

	void connectUtil(TreeLinkNode *node, TreeLinkNode *bro){
		if(!node || (!node->left && !node->right) )return;
		if(node->left && node->right){
			node->left->next = node->right;
		}
		if(bro){
			node->right->next = bro->left;
		}
		connectUtil(node->left, node->right);
		connectUtil(node->right, bro==NULL?NULL:bro->left);
	}
};