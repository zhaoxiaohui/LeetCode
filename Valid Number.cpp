/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    bool isNumber(const char *s) {
		char *end;
		double d = strtod(s, &end);
        if(strlen(s) == strlen(end))return false;
		while(*end !='\0' ){
			if(*end != ' ')return false;
			end++;
		}
		return true;
	}
};