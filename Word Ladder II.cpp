/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
   vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_map<string, vector<string>> traces;
        int word_len = start.length();
        vector<unordered_set<string>> vs(2);
        int pre = 1, cur = 0;
        vs[cur].insert(start);
        char cur_ch;
        string cur_str;
        //bool find_end = false;

        dict.insert(end);
        while(true) {
            pre = !pre;
            cur = !cur;
            vs[cur].clear();
            for(auto it=vs[pre].begin(); it!=vs[pre].end(); it++) {
                dict.erase(*it);
            }
            for(auto it = vs[pre].begin(); it!=vs[pre].end(); it++) {
                cur_str = *it;
                for(int i=0; i<word_len; i++) {
                    cur_ch = cur_str[i];
                    for(char ch='a'; ch<='z'; ch++) {
                        if(ch != cur_ch) {
                            cur_str[i] = ch;
                            if(dict.find(cur_str) != dict.end()) {
                                vs[cur].insert(cur_str);
                                traces[cur_str].push_back(*it);
                                //if(cur_str == end)find_end = true;
                            }
                        }
                    }
                    cur_str[i] = cur_ch;
                }
            }
            if(vs[cur].empty() || vs[cur].count(end)>0)break;
        }
        vector<vector<string>> ret;
        if(vs[cur].count(end)>0) {
            vector<string> path;
            path.push_back(end);
            traceBack(start, end, traces, path, ret);
        }
        return ret;
    }
    //注意集合一般用引用传递，避免不必要的新对象的创建，浪费大量时间
    void traceBack(string start, string end, unordered_map<string, vector<string>> &traces, vector<string> &path, vector<vector<string>> &ret) {
        if(end == start) {
            //vector<string> one(path.size());
            //int ind = 0;
            //for(auto it = path.rbegin(); it!=path.rend();it++){
            //    one[ind++] = *it;
            //}
            //reverse(one.begin(), one.end());
            vector<string> one(path.rbegin(), path.rend());
            ret.push_back(one);
            return;
        }
        for(auto it=traces[end].begin(); it!=traces[end].end(); it++) {
            path.push_back(*it);
            traceBack(start, *it, traces, path, ret);
            path.pop_back();
        }
    }
};