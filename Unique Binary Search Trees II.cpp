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
    vector<TreeNode *> generateTrees(int n) {
		vector<int> nums(n);
		for(int i=1;i<=n;i++)
			nums[i-1] = i;
        vector<TreeNode *> ret = generateTreesUtil(nums, 0, n-1);

		return ret;
    }
	vector<TreeNode *> generateTreesUtil(vector<int> nums, int st, int en){
		vector<TreeNode *> ret;
		if(en<st){
			ret.push_back(NULL);
			return ret;
		}
		if(en==st){
			TreeNode *node = new TreeNode(nums[st]);
			ret.push_back(node);
			return ret;
		}
		for(int i=st;i<=en;i++){
			
			vector<TreeNode *> left = generateTreesUtil(nums, st, i-1);
			vector<TreeNode *> right = generateTreesUtil(nums, i+1, en);
			for(auto l = left.begin();l!=left.end();l++){
				for(auto r = right.begin();r!=right.end();r++){
					TreeNode *root = new TreeNode(nums[i]);
					root->left = *l;
					root->right = *r;
					ret.push_back(root);
				}
			}
		}
		return ret;
	}
};