/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    string minWindow(string S, string T) {
        int slen = S.length();
        int tlen = T.length();
        vector<int> toFind(256, 0);
        vector<int> curFind(256, 0);
        for(int i=0;i<tlen;i++)
            toFind[T[i]]++;
        int count = 0, ret_st = -1, st = 0, ret_len = INT_MAX;
        for(int i=0;i<slen;i++){
            curFind[S[i]]++;
            if(toFind[S[i]] && curFind[S[i]] <= toFind[S[i]])
                count++;
            if(count == tlen){
                while(st<slen && curFind[S[st]] > toFind[S[st]]){
                    curFind[S[st]]--;
                    st++;
                }
                if(ret_len > (i-st+1)){
                    ret_len = i-st+1;
                    ret_st = st;
                }
            }
        }
        return ret_st==-1?"":S.substr(ret_st, ret_len);
    }
};