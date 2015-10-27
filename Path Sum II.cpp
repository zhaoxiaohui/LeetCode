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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > ret;
		vector<int> path;
		pathSumUtil(ret, path, root, 0, sum);
		return ret;
    }
	void pathSumUtil(vector<vector<int> > &ret, vector<int> path, TreeNode *node, int cursum, int sum){
		if(!node)return;
		if(node->left == NULL && node->right == NULL){
			if((cursum+node->val) == sum){
				vector<int> onepath;
				int len = path.size();
				for(int i=0;i<len;i++)
					onepath.push_back(path[i]);
				onepath.push_back(node->val);
				ret.push_back(onepath);
			}
			return;
		}
		path.push_back(node->val);
		if(node->left){
			pathSumUtil(ret, path, node->left, cursum+node->val, sum);
		}
		if(node->right){
			pathSumUtil(ret, path, node->right, cursum+node->val, sum);
		}
	}
};