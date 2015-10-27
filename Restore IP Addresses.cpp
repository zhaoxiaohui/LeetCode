/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
		vector<string> ret;
		restoreIpAddressesUtil(ret, "", s, 0, s.length(), 0);
		return ret;
	}

	void restoreIpAddressesUtil(vector<string> &ret, string cur, string s, int ind, int len, int deep){
		
		if((len-ind) > (4-deep)*3)return;

		if(deep==4 && ind==len){
			ret.push_back(cur);
			return;
		}
		string t;
		int v;
		for(int i=ind;i<len && i<ind+3;i++){
			t = s.substr(ind, i-ind+1);
			if((i-ind+1) >=2 && t[0]=='0')break;
			v = atoi(t.c_str());
			if(v>=0 && v<=255){
				restoreIpAddressesUtil(ret, cur==""?t:cur+"."+t, s, i+1, len, deep+1);
			}
		}
	}
};