/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    vector<vector<string>> partition(string s) {
		vector<vector<string>> ret;
		vector<string> cur;
		partionUtil(s, cur, ret);
		return ret;
	}
	void partionUtil(string s,vector<string> cur, vector<vector<string>> &ret){
		if(s == ""){
			ret.push_back(cur);
			return;
		}
		int len = s.length();
		for(int i=1;i<=len;i++){
			if(isPalindrome(s, 0, i-1)){
				string t = s.substr(0,i);
				cur.push_back(t);
				partionUtil(s.substr(i), cur, ret);
				cur.erase(cur.end()-1);
			}
		}
	}
	bool isPalindrome(string str, int start, int end){
		for(int i=start,j=end;i<j;i++,j--){
			if(str[i] != str[j])return false;
		}
		return true;
	}
};