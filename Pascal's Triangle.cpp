/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
		vector<vector<int> > ret;
		if(numRows == 0)return ret;
		vector<int> first;
		first.push_back(1);
		ret.push_back(first);
		for(int i=1;i<numRows;i++){
			vector<int> row;
			for(int j=0;j<=i;j++){
				if(j==0 || j==i)row.push_back(1);
				else row.push_back(ret[i-1][j]+ret[i-1][j-1]);
			}
			ret.push_back(row);
		}
		return ret;
	}
};