/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")return "0";
        int up = 0, cur;
        int len1 = num1.length(), len2 = num2.length();
        char *ret =  new char[len1+len2+1];
        for(int i=0;i<=len1+len2;i++)ret[i]='0';
        int ind, outer, inner, nextInd = 0;

        int bo1 = 0, bo2 = 0;
        bool neg = false;
        if(num1[0]=='-'){
            neg = ~neg;
            bo1 = 1;
        }
        if(num2[0]=='-'){
            neg = ~neg;
            bo2 = 1;
        }

        for(outer = len2-1; outer>=bo2; outer--){
            ind = nextInd++, up = 0;
            for(inner=len1-1; inner>=bo1; inner--){
                cur = ch2i(ret[ind]) + up + (ch2i(num2[outer])*ch2i(num1[inner]));
                up =  cur / 10;
                cur %= 10;
                ret[ind++] = i2ch(cur);
            }
            if(up)ret[ind++] = i2ch(up);
        }
        string rets;
        rets.assign(ret, ind);
        reverse(rets.begin(), rets.end());
        return neg==true?"-"+rets:rets;
    }

    int ch2i(char ch){
        return ch-'0';
    }

    char i2ch(int n){
        return n+'0';
    }
};