/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int sqrt(int x) {
        double Xn = 1.0, Xn_1;
        while(true) {
            Xn_1 = 0.5 * (Xn + x/Xn);
            if((int)Xn_1 == (int)Xn)return Xn_1;
            Xn = Xn_1;
        }
    }
};