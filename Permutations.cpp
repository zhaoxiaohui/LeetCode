/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> > ret;
		vector<int> row;
		vector<bool> visit(num.size(), false);
		permuteUtil(ret, row,visit, num, num.size());
		return ret;
	}

	void permuteUtil(vector<vector<int> > &ret, vector<int> row, vector<bool> visit,vector<int> num, int deep){
		if(row.size() == deep){
			ret.push_back(row);
			return;
		}
		for(int i=0;i<deep;i++){
			if(!visit[i]){
				visit[i] = true;
				row.push_back(num[i]);
				permuteUtil(ret, row, visit, num, deep);
				row.pop_back();
				visit[i] = false;
			}
		}
	}
};