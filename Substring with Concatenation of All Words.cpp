/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        int slen = S.length();
        int lsize = L.size();
        int word = L[0].length();
        int upper = slen - (word * lsize);
        unordered_map<string, int> toFind;
        unordered_map<string, int> hasFind;
        for(int i=0;i<lsize;++i){
            toFind[L[i]]++;
        }
        int hasFindNum = 0;
        vector<int> ret;
        for(int i=0; i<=upper; ++i){
            hasFind.clear();
            hasFindNum = 0;
            for(int st=i;st<slen; st+=word){
                string find = S.substr(st, word);
                if(toFind.find(find) != toFind.end()){
                    hasFind[find]++;
                    if(hasFind[find] > toFind[find])break;
                    hasFindNum++;
                }else break;
            }
            if(hasFindNum == lsize){
                ret.push_back(i);
            }
        }
        return ret;
    }
};