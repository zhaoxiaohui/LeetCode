/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
   bool isValid(string s) {
		char *op = new char[s.length()];
		int top = 0, n = s.length();
		for(int i=0;i<n;i++){
			if(i==0)op[top++] = s[i];
			else{
				if(check(s[i], op[top-1])){
					top--;
				}else{
					op[top++] = s[i];
				}
			}
		}
		if(top == 0)return true;
		return false;
	}
	bool check(char c, char p){
		if(c ==')' && p=='(')return true;
		if(c =='}' && p=='{')return true;
		if(c ==']' && p=='[')return true;
		return false;
	}
};
