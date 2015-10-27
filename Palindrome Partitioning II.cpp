/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int minCut(string s) {
        int len = s.length();
        if(len <=1) return 0;
        vector<vector<int>> isPal(len, vector<int>(len));
        int curLen = 0;
        for(int i=len-1; i>=0;i--){
            for(int j=i;j<len;j++){
                curLen = j-i+1;
                if(curLen<=2){
                    if(curLen==1)
                        isPal[i][j] = 1;
                    else isPal[i][j] = s[i] == s[j];
                }else{
                    isPal[i][j] = (s[i] == s[j] && isPal[i+1][j-1]);
                }
            }
        }
        vector<int> cut(len, INT_MAX);
        for(int end=0;end<len;end++){
            for(int st=0;st<=end;st++){
                if(isPal[st][end])
                    cut[end] = st==0?0:min(cut[st-1]+1, cut[end]);
            }
        }
        return cut[len-1];
    }
};