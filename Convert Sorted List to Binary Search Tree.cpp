/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
struct TreeNodeW{
	int val;
	int height;
	TreeNodeW *left;
	TreeNodeW *right;
	TreeNodeW(int x):val(x),height(0),left(NULL),right(NULL){}
};
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        TreeNodeW *root = NULL;
		while(head){
			root = insert(head->val, root);
			head = head->next;
		}
		return copyT(root);
    }
	TreeNode *copyT(TreeNodeW *nodew){
		if(nodew != NULL){
			TreeNode *node = new TreeNode(nodew->val);
			node->left = copyT(nodew->left);
			node->right = copyT(nodew->right);
			return node;
		}
		return NULL;
	}
	TreeNodeW *insert(int x, TreeNodeW *root){
		if(root == NULL){
			root = new TreeNodeW(x);
		}else if( x < root->val){
			root->left = insert(x, root->left);
			if(getHeight(root->left)-getHeight(root->right) >=2 ){
				if(x < root->left->val){
					root = ll_rotate(root);
				}else{
					root = lr_rotate(root);
				}
			}
		}else{
			root->right = insert(x, root->right);
			if(getHeight(root->right)-getHeight(root->left) >= 2){
				if(x > root->right->val){
					root = rr_rotate(root);
				}else{
					root = rl_rotate(root);
				}
			}
		}
		root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
		return root;
	}
	TreeNodeW *rr_rotate(TreeNodeW *node){
		TreeNodeW *right = node->right;
		node->right = right->left;
		right->left = node;
		node->height = max(getHeight(node->left), getHeight(node->right))+1;
		right->height = max(getHeight(right->left), getHeight(right->right))+1;
		return right;
	}
	TreeNodeW *ll_rotate(TreeNodeW *node){
		TreeNodeW *left = node->left;
		node->left = left->right;
		left->right = node;
		node->height = max(getHeight(node->left), getHeight(node->right))+1;
		left->height = max(getHeight(left->left), getHeight(left->right))+1;
		return left;
	}
	TreeNodeW *lr_rotate(TreeNodeW *node){
		node->left = rr_rotate(node->left);
		return ll_rotate(node);
	}
	TreeNodeW *rl_rotate(TreeNodeW *node){
		node->right = ll_rotate(node->right);
		return rr_rotate(node);
	}
	int getHeight(TreeNodeW *node){
		if(node)return node->height;
		return -1;
	}
	void printT(TreeNode *node){
		if(!node)return;
		cout<<node->val<<" ";
		printT(node->left);
		printT(node->right);
	}
};