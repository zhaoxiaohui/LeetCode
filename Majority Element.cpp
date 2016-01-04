/**
 *	 Description: https://leetcode.com/problems/majority-element/
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2015-1-4
 */

class Solution {
public:
	//O(nlogn)
	int majorityElementBasic(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];
	}
	//O(n) Boyer-Moore Algorithm
	int majorityElementVoting(vector<int>& nums) {
		int candinate_ind = 0;
		int count = 1;
		for (int ind = 1; ind < nums.size(); ind++) {
			nums[ind] == nums[candinate_ind] ? count++ : count--;
			if (count == 0) {
				count = 1;
				candinate_ind = ind;
			}
		}
		return nums[candinate_ind];
	}

    int majorityElement(vector<int>& nums) {
        //return majorityElementBasic(nums);
        return majorityElementVoting(nums);
    }
};