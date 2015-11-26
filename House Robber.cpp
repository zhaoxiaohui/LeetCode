/**
 *	 Description: https://leetcode.com/problems/house-robber/
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2015-11-19
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size() + 1, 0);
        dp[1] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i + 1] = max(nums[i] + dp[i - 1], dp[i]);
        }
        return dp[nums.size()];
    }
};