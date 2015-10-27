/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> visited;
        dict.insert(end);
        visited.insert(start);
        queue<string> ques;
        ques.push("S");
        ques.push(start);
        string cur, next;
        char cur_ch;
        int word = start.length();
        unordered_set<string>::iterator usit;
        int step = 0;
        while(!ques.empty()){
            cur = ques.front();
            ques.pop();
            if(cur == "S" && !ques.empty()){
                step++;
                ques.push("S");
                continue;
            }
            for(int i=0; i<word; ++i){
                cur_ch = cur[i];
                for(char ch='a'; ch<='z'; ++ch){
                    if(cur_ch == ch)continue;
                    cur[i] = ch;
                    usit = dict.find(cur);
                    if(usit!=dict.end() && visited.find(cur)==visited.end()){
                        visited.insert(cur);
                        if(cur == end)return step+1;
                        ques.push(cur);
                    }
                }
                cur[i] = cur_ch;
            }
        }
        return 0;
    }
};