/**
 *	 Description: https://leetcode.com/problems/number-of-1-bits/
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2015-11-26
 */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            count += 0x1 & n;
            n >>= 1;
        } 
        return count;
    }
};