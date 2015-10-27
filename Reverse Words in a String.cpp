/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
   void reverseWords(string &s) {
		int len = s.length();
		if(len  == 0)return;
		//remove leading spaces
		int realStart = 0, realLen=len;
		while(s[realStart]==' ')realStart++;
		if(realStart == len){
			s="";
			return;
		}
		string ret="";
		//reverse every single word
		int curStart, curEnd = realStart;
		while(curEnd < len){
			curStart = curEnd;
			while(s[curEnd]!=' ' && s[curEnd]!='\0')curEnd++;
			realLen = curEnd; //for trailing spaces
			reverseWord(s, curStart, curEnd-1);
			//skip spaces
			if(ret == "")ret = s.substr(curStart, curEnd-curStart);
			else
				ret =  ret + " " + s.substr(curStart, curEnd-curStart);
			while(s[curEnd]==' ')curEnd++;
		}
		//reverse whole string
		//ret = s.substr(realStart, realLen-realStart);
		reverseWord(ret,0, ret.length()-1);
		s = ret;
	}
	void reverseWord(string &s, int start, int end){
		char temp;
		for(int i=start, j=end;i<j; i++, j--){
			temp = s[i];
			s[i] = s[j];
			s[j] = temp;
		}
	}
};