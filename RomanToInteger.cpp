/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    map<char, int> romans;
	Solution(){
		//I(1)£¬V(5)£¬X(10)£¬L(50)£¬C(100)£¬D(500)£¬M(1000)

		romans['I'] = 1;
		romans['V'] = 5;
		romans['X'] = 10;
		romans['L'] = 50;
		romans['C'] = 100;
		romans['D'] = 500;
		romans['M'] = 1000;
	}
    int romanToInt(string s) {
		int len = s.length();
		int res = 0, i;
		for(i=0;i<len-1;i++){
			if(romans[s[i]] >= romans[s[i+1]]){
				res += romans[s[i]];
			}else res-=romans[s[i]];
		}
		res += romans[s[i]];
		return res;
	}
};
