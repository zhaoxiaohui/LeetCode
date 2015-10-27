/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
     bool isMatch(const char *s, const char *p) {
        if(*p == '\0')return *s == '\0';
        if(*(p+1) == '*'){
            while((*s == *p || *p=='.') && *s!='\0'){
                if(isMatch(s, p+2))
                    return true;
                s++;
            }
            return isMatch(s, p+2);
        }
        if(*s == '\0')return false;
        return (*p==*s || *p=='.') && isMatch(s+1, p+1);
    }
};
