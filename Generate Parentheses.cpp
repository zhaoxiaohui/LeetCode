/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> ret;
		string str="(";
		generateParenthesisUtil(1,n,1,0,str,ret);
		return ret;
	}
	void generateParenthesisUtil(int deep, int n,int leftnum,int rightnum, string str, vector<string> &ret){
		if(deep == 2*n){
			ret.push_back(str);
			return;
		}
		string temp="";
		for(int i=rightnum+1;i<=leftnum;i++){
			temp+=")";
			generateParenthesisUtil(deep+1,n,leftnum,i,str+temp, ret);
		}
		temp = "";
		for(int i=leftnum+1;i<=n;i++){
			temp+="(";
			generateParenthesisUtil(deep+1,n,i,rightnum,str+temp, ret);
		}
	}
};
