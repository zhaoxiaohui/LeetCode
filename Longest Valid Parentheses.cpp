/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        int slen = s.length();
        int count = 0, ret = 0;
        stack<int> len;
        for(int i=0; i<slen; ++i){
            if(s[i]=='('){
                len.push(count);
                count = 0;
            }else if(!len.empty()) {
                count += (1+len.top());
                len.pop();
                ret = max(ret, count);
            }else{
                count = 0;
            }
        }
        return ret*2;
    }
};