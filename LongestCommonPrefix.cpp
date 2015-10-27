/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
		return longestCommonPrefix_2(strs);
	}
	string longestCommonPrefix_2(vector<string> &strs){
		int n = strs.size();
		if(n <= 1)return n==1?strs[0]:"";
		double iter_d = log(n)/log(2);
		int iter = (int)iter_d-iter_d ==0.0?(int)iter_d:(int)iter_d+1;
		int skip = 1, i;
		while(iter--){
			i = 0;
			while(i<n){
				strs[i] = longestCommonPrefix(strs[i], i+skip>=n?strs[i]:strs[i+skip]);
				i += 2*skip;
			}
			skip *= 2;
		}
		return strs[0];
	}
	string longestCommonPrefix_1(vector<string> &strs) {
		int n = strs.size();
		if(n <= 1)return n==1?strs[0]:"";
		string ret = strs[0];
		for(int i=1;i<n;i++){
			ret = longestCommonPrefix(ret, strs[i]);
		}
		return ret;
	}
	string longestCommonPrefix(string str1, string str2){
		int len1 = str1.length(), len2 = str2.length();
		int i,j;
		for(i=0, j=0;i<len1 && j<len2; i++,j++){
			if(str1[i]!=str2[j]){
				break;
			}
		}
		return i<=j?str1.substr(0, i):str2.substr(0, j);
	}
};
