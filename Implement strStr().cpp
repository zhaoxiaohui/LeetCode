/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    char *strStr(char *haystack, char *needle){
        return strStr2(haystack, needle);
    }
    char *strStr2(char *haystack, char *needle){
        if(!*needle)return haystack;
	    	char *iterator = (char *)haystack, *p2 = (char *)needle;
		    while(*++p2 != '\0'){++iterator;}
	    	char *p1 = (char *)haystack,*p1it,*p2it;
	     	while(*iterator != '\0'){
	    		p1it = p1,p2it = (char *)needle;
		    	while(*p1it == *p2it && *p1it!='\0'){
		    		p1it++;
		    		p2it++;
		    	}
		    	if(*p2it=='\0')return p1;
    		    	p1++;
    			iterator++;
	    	}
	    return NULL;
    }
    char *strStr3(char *haystack,char *needle) {
		if(!haystack || !needle)return NULL;
		int len = strlen(needle);
		int *next = new int[len];
		get_nextval(needle, next);
		int i=0,j=0,index=0;
		while(haystack[i]!='\0' && needle[j]!='\0'){
			if(haystack[i]==needle[j]){
				i++,j++;
			}else{
				index += j-next[j];
				if(next[j]!=-1){
					j = next[j];
				}else{
					i++,j=0;
				}
			}
		}
		if(needle[j]=='\0')return haystack+index;
		return NULL;
	}
	void get_nextval(char *T, int next[])
	{
		int j = 0, k = -1;
		next[0] = -1;
		while ( T[j/*+1*/] != '\0' )
		{
			if (k == -1 || T[j] == T[k])
			{
				++j; ++k;
				if(T[j]=='\0')break;
				if (T[j]!=T[k])
					next[j] = k;
				else
					next[j] = next[k];
			}// if
			else
				k = next[k];
		}// while
	}// get_nextval　
};