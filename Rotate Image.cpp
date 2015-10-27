/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
		int adj = 0, len = matrix.size(), adjlen = len/2, rowsize = matrix.size()-1;
		int x, y, nexti, nextj, tmpvalue, curvalue, nexttmp;
		int cycle;
		while(adj < adjlen){
			x= adj, y = adj;
			while(y<len-1){
				cycle = 4;
				nexti = x, nextj = y;
				curvalue = matrix[nexti][nextj];
				while(cycle--){
					nexttmp = nexti;
					nexti = nextj;
					nextj = rowsize-nexttmp;
					tmpvalue = matrix[nexti][nextj];
					matrix[nexti][nextj] = curvalue;
					curvalue = tmpvalue;
				}
				y++;
			}
			adj++;
			len--;
		}
	}
};