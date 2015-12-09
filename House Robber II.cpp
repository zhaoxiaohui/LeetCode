/**
 *	 Description: https://leetcode.com/problems/house-robber-ii/
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2015-12-09
 */

class Solution {
public:
    //注：空间可以压缩到O(1)
    int rob_line(vector<int>& nums, int start, int end) {
        if (start >= end) return 0;
        if (end - start == 1) return nums[start];
        vector<int> dp(end - start + 1, 0);
        int dp_ind = 1;
        dp[dp_ind] = nums[start];
        for (int i = start + 1; i < end; i++) {
            dp_ind++;
            dp[dp_ind] = max(nums[i] + dp[dp_ind - 2], dp[dp_ind - 1]);
        }
        return dp[dp_ind];
    }
    
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        return max(rob_line(nums, 0, nums.size() - 1), rob_line(nums, 1, nums.size()));
    }
};