/**
 *	 Description: https://leetcode.com/problems/majority-element/
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2015-1-4
 */

class Solution {
public:
    // there will be no more than 2 elements
    // percen: 1/3 + 1/3 > 2/3, the other must be lower than 1/3
    vector<int> majorityElement(vector<int>& nums) {
    	int counta = 0, countb = 0;
    	int counta_ind = 0, countb_ind = 0;
    	for (int ind = 0; ind < nums.size(); ind++) {
    		if (counta == 0) {
    			counta++;
    			counta_ind = ind;
    		} else if (nums[ind] == nums[counta_ind]) {
    			counta++;
    		} else if (countb == 0) {
    			countb++;
    			countb_ind = ind;
    		} else if(nums[ind] == nums[countb_ind]) {
    			countb++;
    		} else {
    			counta--;
    			countb--;
    		}
    	}
    	counta = countb = 0;
    	for (int ind = 0; ind < nums.size(); ind++) {
    		if (nums[ind] == nums[counta_ind]) counta++;
    		else if (nums[ind] == nums[countb_ind]) countb++;
    	}
    	vector<int> ret;
    	if (counta > nums.size() / 3) {
    		ret.push_back(nums[counta_ind]);
    	}
    	if (countb > nums.size() / 3) {
    		ret.push_back(nums[countb_ind]);
    	}
    	return ret;
    }
};