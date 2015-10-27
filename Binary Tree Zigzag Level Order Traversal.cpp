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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ret;
		vector<int> level;
		deque<TreeNode *> nodes;
		int k = 1;
		TreeNode *t;
		nodes.push_back(NULL);
		nodes.push_back(root);
		while(!nodes.empty()){
			if(k % 2 != 0){
				t = nodes.back();
				nodes.pop_back();
			}else{
				t = nodes.front();
				nodes.pop_front();
			}
			if(!t){
				k++;
				if(k % 2 != 0){
					nodes.push_front(NULL);
				}else{
					nodes.push_back(NULL);
				}
				if(level.size() == 0)break;
				ret.push_back(level);
				level.clear();
			}else{
				level.push_back(t->val);
				if(k % 2 == 0){
					if(t->right)nodes.push_back(t->right);
					if(t->left)nodes.push_back(t->left);
				}else{
					if(t->left)nodes.push_front(t->left);
					if(t->right)nodes.push_front(t->right);
					
				}
			}
		}
		return ret;
    }
};