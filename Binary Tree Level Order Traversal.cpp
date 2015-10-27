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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ret;
		queue<TreeNode *> nodes;
		nodes.push(root);
		nodes.push(NULL);
		TreeNode *t;
		vector<int> level;
		while(!nodes.empty()){
			t = nodes.front();
			nodes.pop();
			if(!t){
				nodes.push(NULL);
				if(level.size() == 0)break;
				ret.push_back(level);
				level.clear();
			}else{
				level.push_back(t->val);
				if(t->left)nodes.push(t->left);
				if(t->right)nodes.push(t->right);
			}
		
		}
		return ret;
    }
};