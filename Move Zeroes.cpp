/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return;
        int zero = 0, nonezero;
        while (nums[zero] != 0) {
            zero++;
        }
        nonezero = zero + 1;
        for (; nonezero < len; ) {
            while (nonezero < len && nums[nonezero] == 0) {
                nonezero++;
            }
            if (nonezero == len) break;
            while (zero < nonezero && nums[zero] != 0) {
                zero++;
            }
            if (zero == nonezero) break;
            swap(nums[zero], nums[nonezero]);
        }
    }
};