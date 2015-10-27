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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ret;
		if(!root) return ret;
		queue<TreeNode *> nodes;
		deque<TreeNode *> nodeslist;
		nodes.push(root);
		nodes.push(NULL);
		nodeslist.push_back(NULL);
		nodeslist.push_back(root);
		TreeNode *t;
		while(!nodes.empty()){
			t = nodes.front();
			nodes.pop();
			if(!t){
				if(nodes.empty() || nodes.front() == NULL)break;
				nodeslist.push_front(NULL);
				nodes.push(NULL);
			}else{
				if(t->right){
					nodes.push(t->right);
					nodeslist.push_front(t->right);
				}
				if(t->left){
					nodes.push(t->left);
					nodeslist.push_front(t->left);
				}
			}
		}
		vector<int> level;
		while(!nodeslist.empty()){
			t = nodeslist.front();
			nodeslist.pop_front();
			if(!t){
				if(level.size() != 0){
					ret.push_back(level);
					level.clear();
				}
			}else{
				level.push_back(t->val);
			}
		}
		if(level.size() != 0)ret.push_back(level);
		return ret;
    }
};