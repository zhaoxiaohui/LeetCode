/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
		//return isMatchCir((char *)s, (char *)p);
		return isMatchRe((char *)s, (char *)p);
	}

	bool isMatchRe(char *s, char *p){
		if(*p == '*'){
			while(*p == '*')p++;
			if(!(*p))return true;
			while(*s){
				char *ts = s, *tp = p;
				while(*ts && (*ts==*tp || *tp=='?')){
					ts++, tp++;
					if(*tp == '*')break;
				}
				if(!(*ts) && !(*tp))return true;
				if(*tp == '*')return isMatchRe(ts, tp);
				if(!(*ts))return false;
				s++;
			}
		}
		if(*s && *p=='?')return isMatchRe(s+1, p+1);
		if(*s && *p==*s)return isMatchRe(s+1, p+1);
		return *s=='\0' && *p=='\0';
	}

	bool isMatchCir(char *s, char *p){
		char *pres = NULL, *prep = NULL;
		while(*s){
			if(*p=='?' || *s==*p){
				p++, s++;
			}else if(*p=='*'){
				while(*p == '*')p++;
				if(!(*p))return true;
				pres = s;
				prep = p;
			}else{
				if(!pres)return false;
				s = ++pres;
				p = prep;
			}
		}
		while(*p=='*')p++;
		return *s=='\0' && *p=='\0';
	}
};