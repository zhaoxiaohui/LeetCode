/**
 *   Description: https://leetcode.com/problems/minimum-size-subarray-sum/
 *        Author: zhaoxiaohui
 *          Site: zhaoxiaohui.sinaapp.com
 *          Date: 2015-11-11
 */

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int slow = 0, cur_s = 0, ret = INT_MAX;
        for (int fast = 0; fast < nums.size(); ++fast) {
            cur_s += nums[fast];
            if (cur_s >= s) {
                while (cur_s - nums[slow] >= s) {
                    cur_s -= nums[slow++];
                }
                ret = min(ret, fast - slow + 1);
            }
        }
        return ret == INT_MAX ? 0 : ret;
    }
};