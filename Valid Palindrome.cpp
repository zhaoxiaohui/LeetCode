/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    bool isPalindrome(string s) {
		int len = s.length();
		if(len<=1)return true;
		for(int i=0,j=len-1;i<j;i++,j--){
			while(i<j && !isAlphanumeric(s[i]))i++;
			while(i<j && !isAlphanumeric(s[j]))j--;
			if(i>j)return false;
			if(!equal(s[i],s[j]))return false;
		}
		return true;
	}
	bool isAlphanumeric(char c){
		if( (c>='a' && c<='z') || (c>='A' && c<='Z') || c>='0' && c<='9')return true;
		return false;
	}
	bool equal(char c1, char c2){
		if(c1>='a'&& c1<='z' && c2>='A' && c2<='Z'){
			return c1 == c2-'A'+'a';
		}
		if(c2>='a'&& c2<='z' && c1>='A' && c1<='Z'){
			return c1 == c2-'a'+'A';
		}
		return c1==c2;
	}
};