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
		if(!node)return;
		node->next = bro;
		if(node->right)
			connectUtil(node->right, getFirstBro(node->next));
		if(node->left)
			connectUtil(node->left, node->right==NULL?getFirstBro(node->next):node->right);
	}
	TreeLinkNode *getFirstBro(TreeLinkNode *node){
		if(!node)return NULL;
		while(node){
			if(node->left)return node->left;
			if(node->right)return node->right;
			node = node->next;
		}
		return NULL;
	}
};