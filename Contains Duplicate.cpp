/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> table;
        for (int i = 0; i < nums.size(); i++) {
            table[nums[i]]++;
            if (table[nums[i]] >= 2) {
                return true;
            }
        }
        return false;
    }
};