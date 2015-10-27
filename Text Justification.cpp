/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> ret;
		vector<string> cur;
		int len = 0, wordslen = words.size();
		for(int i = 0; i<wordslen ; i++){
			if(len+(len==0?0:1)+words[i].length() > L){
				addOneLine(ret, cur, len, false, L);
				cur.clear();
				len = 0;
			}
			cur.push_back(words[i]);
			len += (len==0?0:1)+words[i].length();
		}
		addOneLine(ret, cur, len ,true, L);
		return ret;
	}
	void addOneLine(vector<string> &ret,vector<string> cur,  int len, bool islast, int L){
		//if(cur.size() ==0)return;
		string line = "";
		if(islast){
			for(auto it = cur.begin();it!=cur.end();it++){
				if(it!=cur.begin())line += " ";
				line += *it;
			}
		}else{
			int spaces = L- (len - cur.size() + 1);
			int oneSpace = cur.size()==1?spaces:spaces / (cur.size()-1), extraSpace = cur.size()==1?0:spaces % (cur.size()-1), t;
			for(int i=0;i<cur.size();i++){
				if(i!=0){
				    if(extraSpace){
						extraSpace--;
						line += " ";
					}
					t = oneSpace;
					while(t--){
						line += " ";
					}
				}
				line += cur[i];
			}
		}
		line.resize(L, ' ');
		ret.push_back(line);
	}
};