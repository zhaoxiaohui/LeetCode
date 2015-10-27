/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
		vector<int> ret;
		int up = 1, cur;
		for(auto it = digits.rbegin();it!=digits.rend();it++){
			cur = *it + up;
			up = cur / 10;
			cur %= 10;
			ret.push_back(cur);
		}
		if(up)ret.push_back(up);
		reverse(ret.begin(), ret.end());
		return ret;
	}
};