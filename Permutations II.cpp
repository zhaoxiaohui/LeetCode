/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
		vector<vector<int> > ret;
		vector<int> row;
		vector<bool> visit(num.size(), false);
		sort(num.begin(), num.end());
		permuteUtil(ret, row,visit, num, num.size());
		return ret;
	}

	void permuteUtil(vector<vector<int> > &ret, vector<int> row, vector<bool> visit,vector<int> num, int deep){
		if(row.size() == deep){
			ret.push_back(row);
			return;
		}
		int last_index = -1;
		for(int i=0;i<deep;i++){
			if(last_index !=-1 && num[i]==num[last_index])continue;
			if(!visit[i]){
				visit[i] = true;
				row.push_back(num[i]);
				permuteUtil(ret, row, visit, num, deep);
				row.pop_back();
				visit[i] = false;
				last_index = i;
			}
		}
	}
};