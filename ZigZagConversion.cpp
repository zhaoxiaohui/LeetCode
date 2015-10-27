/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
	string convert(string s, int nRows) {
	    if(nRows == 1)return s;
		vector<string> maze(nRows);
		int row=-1, forward = 1, len = s.length(), ind=0;
		while(ind < len){
			if(row+forward == nRows){
				forward = -1;
			}else if(row+forward == -1){
				forward = 1;
			}
			maze[row+=forward].push_back(s[ind++]);
		}
		string ret = "";
		for(int i=0;i<nRows;i++){
			ret += maze[i];
		}
		return ret;
	}
};
