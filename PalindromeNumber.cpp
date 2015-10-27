/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
   bool isPalindrome(int x) {
		if(x < 0)return false;
		int xt=0, t = x;
		while(t){
			xt = xt*10 +  t%10;
			t/=10;
		}
		if(xt == x)return true;
		return false;
	}
};
