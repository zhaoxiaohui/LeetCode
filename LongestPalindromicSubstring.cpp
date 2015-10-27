/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    string longestPalindrome(string s) {
        string str = prepare(s);
        int c = 0, r = 0, i_mirror;
        int len = str.length();
        vector<int> p(len, 0);
        for(int i=0; i<len; i++) {
            i_mirror = 2*c - i;
            p[i] = r>i?min(r-i, p[i_mirror]):0;
            while(str[i+1+p[i]] == str[i-1-p[i]]) {
            p[i]++;
            }
            if(i+p[i] > r) {
                r = i+ p[i];
                c = i;
            }
        }
        int retc=0, retl=0;
        for(int i=0; i<len; i++) {
            if(retl < p[i]) {
                retl = p[i];
                retc = i;
            }
        }
        return s.substr((retc-retl-1)/2, retl);
    }
    string prepare(string &s) {
        string ret = "^$";
        int len = s.length();
        for(int i=0; i<len; ++i) {
            ret += "#" + s.substr(i, 1);
        }
        ret += "#$";
        return ret;
    }

};
