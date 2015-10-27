/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool isN = (dividend < 0 && divisor > 0) || (dividend >0 && divisor <0);
        long long lldividend = abs(static_cast<long long>(dividend));
        long long lldivisor  = abs(static_cast<long long>(divisor));
        long long cur, ret = 0;
        long long tmp;
        while(lldividend >= lldivisor) {
            cur = 1;
            tmp = lldivisor;
            while( (tmp<<1) <= lldividend) {
                cur <<= 1;
                tmp <<= 1;
            }
            ret += cur;
            lldividend -= tmp;
        }
        return isN == true?-ret:ret;
    }
};