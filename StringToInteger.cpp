/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int atoi(const char *str) {
        long long res = 0, neg = 0;
        while(*str == ' ')str++;
        if(*str=='+')str++;
        if(*str=='-')str++, neg = 1;
        while(*str != '\0'){
            if(*str>='0' && *str<='9'){
                res = res*10 +(*str-'0');
                if(!neg && res>2147483647)
                    return 2147483647;
                if(neg && (res > 2147483648))
                    return -2147483648;
                str++;
            }else break;
        }
        if(neg){
            res = -res;
            if(res>0)return -2147483648;
            return res;
        }else{
            if(res<0)return 2147483647;
            return res;
        }
    }
};
