/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    typedef string::iterator sit;
	bool isScramble(string s1, string s2) {
		if(s1.length()!=s2.length())return false;
		return isScrambleRe(s1.begin(), s2.begin(), s1.size());
	}
	bool isScrambleRe(sit s1, sit s2, int len){
		if(!hasSameLetters(s1, s2, len))return false;
		if(len==0 || len==1)return true;
		for(int i=1;i<len;i++){
			if(isScrambleRe(s1, s2, i)&&isScrambleRe(s1+i, s2+i, len-i) ||
				isScrambleRe(s1, s2+len-i, i)&&isScrambleRe(s1+i, s2, len-i))
				return true;
		}
		return false;
	}

	bool hasSameLetters(sit s1, sit s2, int len){
		int count[256] = {0};
		for(int i=0;i<len;i++)count[*s1++]++;
		for(int i=0;i<len;i++)count[*s2++]--;
		for(int i=0;i<256;i++)
			if(count[i]!=0)return false;
		return true;
	}
};