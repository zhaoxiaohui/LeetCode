/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

struct ANA{
	int count;
	int first;
	ANA():count(0),first(-1){}
};
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
		vector<string> ret;
		int len = strs.size();
		if(len<=1)return ret;
		map<string,ANA> ha;
		string str;
		int t;
		for(int i=0;i<len;i++){
			str = strs[i];
			sort(str.begin(), str.end());
			t = ++ha[str].count;
			if(t == 1)ha[str].first = i;
			if(t>=2){
				if(t==2){
					ret.push_back(strs[ha[str].first]);
				}
				ret.push_back(strs[i]);
			}
		}
		return ret;
    }
};