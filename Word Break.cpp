/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
		int len = s.length();
		bool  *find = new bool [len+1];
		memset(find, false, sizeof(bool)*(len+1));
		string sub;
		find[len] = true; //start from index len(it is an empty string)
		for(int i=len-1;i>=0;i--){ //start form i
			for(int j=i+1;j<=len;j++){ //end at j
				sub = s.substr(i, j-i);
				if(dict.find(sub)!=dict.end() && find[j]){
					find[i] = true;
					break;
				}
			}
		}
		return find[0];//start from index 0
    }
};