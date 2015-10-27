/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        int next = 1;
        int ind = s.length() - 1;
        while (ind >= 0) {
            ret += next * (s[ind--] - 'A' + 1);
            next *= 26;
        }
        return ret;
    }
};