/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
		int rows = matrix.size();
		if(rows == 0)return;
		int cols = matrix[0].size();
		bool *zerosc = new bool[cols];
		bool *zerosr = new bool[rows];
		memset(zerosc, false, sizeof(bool)*cols);
		memset(zerosr, false, sizeof(bool)*rows);
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				if(matrix[i][j]==0){
					zerosr[i] = true;
					zerosc[j] = true;
				}
			}
		}
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				if(zerosc[j] || zerosr[i]){
					matrix[i][j] = 0;
				}
			}
		}
		delete []zerosr;
		zerosr = NULL;
		delete []zerosc;
		zerosc = NULL;
	}
};