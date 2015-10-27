/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int lengthOfLastWord(const char *s) {
		char *t = (char *)s;
		int count = 0, ret=0;
		while(*t != '\0'){
			if(*t == ' '){
				if(count)ret = count;
				count = 0;
			}else{
				count++;
			}
			t++;
		}
		if(count)ret = count;
		return ret;
	}
};