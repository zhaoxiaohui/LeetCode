/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    string addBinary(string a, string b) {
		string ret = "";
		int up = 0, tmp;
		int alen = a.length()-1, blen = b.length()-1;
		while(alen>=0 || blen>=0){
			tmp = up + (alen<0?0:(a[alen]=='1'?1:0)) + (blen<0?0:(b[blen]=='1'?1:0));
			up = tmp / 2;
			tmp %= 2;
			ret.push_back(tmp==1?'1':'0');
			alen--, blen--;
		}
		if(up != 0)ret.push_back('1');
		reverse(ret.begin(), ret.end());
		return ret;
	}
};