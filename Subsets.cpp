/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
		//sort
		sort(S.begin(), S.end());
		vector<vector<int> > ret;
		vector<int> curret;
		subsetsWithDupUtil(ret, curret, S, S.size(), 0);
		return ret;
	}
	void subsetsWithDupUtil(vector<vector<int> > &ret,vector<int> curret, vector<int> S, int deep, int curdeep){
		if(curdeep == deep){
			ret.push_back(curret);
			return;
		}
		//contain it
		curret.push_back(S[curdeep]);
		subsetsWithDupUtil(ret, curret, S, deep, curdeep+1);
		
		//without it
		curret.pop_back();
		//while(curdeep<deep-1 && S[curdeep]==S[curdeep+1])curdeep++;
		subsetsWithDupUtil(ret, curret, S, deep, curdeep+1);
	}
};