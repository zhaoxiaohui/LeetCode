/**
 *	 Description: https://leetcode.com/problems/bitwise-and-of-numbers-range/
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2015-1-11
 */
class Solution {
public:
    // 01 11
    // 01 01
    // common header
    int rangeBitwiseAnd(int m, int n) {
        int r = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            r++;
        }
        return n <<= r;
    }
};