/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    string simplifyPath(string path) {
		if(path.length() == 1 && path[0]=='/')return path;
        string ret = "";
		int skip = 0;
		simplifyPathUtil(path, path.length()-1, skip, ret);
		return ret.length()==0?"/":ret.length()==1?ret:ret.substr(0, ret.length()-1);
    }
	void simplifyPathUtil(string path, int ind, int &skip, string &ret){
		if(ind<0)return;
		int len = 0;
		while(ind>=0 && path[ind]=='/'){
			ind--;
		}
		if(ind<=0){
			ret = "/" + ret;
			return;
		}
		while(ind>=0 && path[ind]!='/'){
			len++;
			ind--;
		}
		string cur = len==0?"":path.substr(ind+1, len);
		if(cur == ".."){
			skip++;
			//simplifyPathUtil(path, ind-1, skip,  ret);
		}else if(cur=="."){
		}else{
			if(skip > 0){
				skip--;
			}else{
				ret = cur + "/" + ret;
			}
		}
		simplifyPathUtil(path, ind, skip, ret);
	}
};