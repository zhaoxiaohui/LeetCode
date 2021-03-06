/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        if (num == 1) return true;
        while(num != 0 && num % 2 == 0) num /= 2;
        while(num != 0 && num % 3 == 0) num /= 3;
        while(num != 0 && num % 5 == 0) num /= 5;
        if (num == 1) return true;
        else return false;
    }
};