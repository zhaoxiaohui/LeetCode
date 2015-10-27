/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int reverse(int x) {
        bool isN = x < 0 ? true : false;
        string str = itos(abs(x));
        int res = atoi(str.c_str());
        return isN == true? -res : res;
    }
    string itos(int x){
        string ret;
        while(x){
            ret.push_back(x%10+'0');
            x /= 10;
        }
        return ret;
    }
};
