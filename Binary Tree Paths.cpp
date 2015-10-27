/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void binaryTreePathsCrawl(vector<string> &ret, string path, TreeNode *cur) {
        if (cur == NULL) {
            return;
        }
        string cur_word = to_string(cur->val);
        if (path != "") path += "->";
        if (cur->left == NULL && cur->right == NULL) {
            ret.push_back(path + cur_word);
            return;
        }
        if (cur->left != NULL) {
            binaryTreePathsCrawl(ret, path + cur_word, cur->left);
        }
        if (cur->right != NULL) {
            binaryTreePathsCrawl(ret, path + cur_word, cur->right);
        }
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        binaryTreePathsCrawl(ret, "", root);
        return ret;
    }
};