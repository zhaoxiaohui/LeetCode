/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > ret;
		vector<int> cur;
		combineUtil(ret, cur, 1, n, k);
		return ret;
    }
	void combineUtil(vector<vector<int> > &ret, vector<int> cur, int st, int n, int k){
		if((n-st+1) < (k-cur.size()))return;
		if(cur.size() == k){
			ret.push_back(cur);
			return;
		}
		//without
		//combineUtil(ret, cur, st + 1, n, k);
		
		for(int i=st;i<=n;i++){
			//need it
			cur.push_back(i);
			combineUtil(ret, cur, i+1, n, k);
			//no
			cur.pop_back();
			
		}
	}
};