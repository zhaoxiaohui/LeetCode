/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> ret;
        vector<string> cret;
        wordBreakUtil(s, s.length()-1, ret, cret, dict);

        return ret;
    }
    void wordBreakUtil(string s, int end, vector<string> &ret, vector<string> &cret, unordered_set<string> &dict) {
        if(end == -1) {
            if(!cret.empty()) {
                auto it = cret.rbegin();
                string sret = *it;
                for(++it; it!=cret.rend(); it++) {
                    sret = sret + " " + *it;
                }
                ret.push_back(sret);
            }
            return;
        }
        string sub;
        for(int i=end; i >= 0; i--) {
            sub = s.substr(i, end-i+1);
            if(dict.find(sub) != dict.end()) {
                cret.push_back(sub);
                wordBreakUtil(s, i-1, ret, cret, dict);
                cret.pop_back();
            }
        }
    }
};