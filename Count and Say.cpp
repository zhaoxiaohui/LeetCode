/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    string countAndSay(int n) {
		string ret  = "1";
		while(--n){
			ret = countSay(ret);
		}
		return ret;
	}
	string toString(int c, char ch){
		return to_string(c)+to_string(ch-'0');
	}
	string countSay(string str){
		int len = str.length();
		int count = 1, ind = 0;
		string ret = "";
		for(int i=1;i<len;i++){
			if(str[i]==str[i-1]){
				count++;
			}else{
				ret += toString(count, str[i-1]); 
				count=1;
			}
		}
		ret += toString(count, str[len-1]);
		return ret;
	}
};