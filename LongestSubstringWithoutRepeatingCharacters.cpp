/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		vector<bool> exists(256, 0);
		int ret=0, start=0, end=0;
		int len = s.length(), st = 0;
		while(end < len){
			if(!exists[s[end]]){
				exists[s[end++]] = true;
			}else{
				exists[s[start++]] = false;
			}
			ret = max(ret, end-start);
		}
		return ret;
	}

};
