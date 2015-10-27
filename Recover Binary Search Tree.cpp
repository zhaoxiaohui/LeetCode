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
   void recoverTree(TreeNode *root) {
		//recoverTreeInOrder(root);
		//recoverTreeWithPointers(root);
		recoverTreeMorris(root);
	}

	void recoverTreeInOrder(TreeNode *root){
		vector<TreeNode *> in;
		inOrder(root, in);
		TreeNode *first = NULL, *second = NULL;
		for(int i=1;i<in.size();i++){
			if(in[i]->val > in[i-1]->val)continue;
			if(!first)
				first = in[i-1];
			second = in[i];
		}
		swap(first, second);
	}
	void swap(TreeNode *one, TreeNode *two){
		if(!one || !two)return;
		int t = one->val;
		one->val = two->val;
		two->val = t;
	}
	void inOrder(TreeNode *node, vector<TreeNode *> &in){
		if(!node)return;
		inOrder(node->left, in);
		in.push_back(node);
		inOrder(node->right, in);
	}

	void recoverTreeWithPointers(TreeNode *root){
		TreeNode *preNode = NULL, *first = NULL, *second = NULL;
		recoverTreeWithPointersUtil(root, preNode, first, second);
		swap(first, second);
	}

	void recoverTreeWithPointersUtil(TreeNode *curNode, TreeNode *&preNode, TreeNode *&first, TreeNode *&second){
		if(!curNode)return;
		recoverTreeWithPointersUtil(curNode->left, preNode, first, second);
		if(preNode){
			if(preNode->val > curNode->val){
				if(!first)first = preNode;
				second = curNode;
			}
		}
		preNode = curNode;
		recoverTreeWithPointersUtil(curNode->right, preNode, first, second);
	}

	void recoverTreeMorris(TreeNode *root){
		TreeNode *cur = root, *pre = NULL, *first = NULL, *second=NULL, *t;
		while(cur){
			if(cur->left == NULL){
				comp(pre, cur, first, second);
				pre = cur;
				cur = cur->right;
			}else{
				t = cur->left;
				while(t->right && t->right != cur){
					t = t->right;
				}
				if(t->right == NULL){
					t->right = cur;
					cur = cur->left;
				}else{
					comp(pre, cur, first, second);
					pre = cur;
					t->right = NULL;
					cur = cur->right;
				}
			}
		}
		swap(first, second);
	}

	void comp(TreeNode *pre,TreeNode *cur, TreeNode *&first, TreeNode *&second){
		if(pre && pre->val > cur->val){
			if(!first)first = pre;
			second = cur;
		}
	}
};