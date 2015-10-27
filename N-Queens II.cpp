/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int totalNQueens(int n) {
		int ret = 0;
		totalNQueensUtil(ret, 0, 0, 0, 0, n);
		return ret;
	}
	void totalNQueensUtil(int &ret, int row, int maskrow, int maska1, int maska2,  int rows){
		if(row == rows){
			ret++;
			return;
		}
		int po = 1, m1, m2, m3;
		for(int i=0;i<rows;i++){
			po <<= 1;
			m1 = po, m2 = 1<<(row+i), m3 = 1<<(rows-1+row-i);
			if( check(m1, m2, m3, maskrow, maska1, maska2) ){
				totalNQueensUtil(ret, row+1, maskrow | m1, maska1 | m2, maska2 | m3, rows);
			}
		}
	}

	bool check(int m1, int m2, int m3, int mask1, int mask2, int mask3){
		if(((m1 ^ mask1) & m1) && ((m2 ^ mask2) & m2) && ((m3 ^ mask3) & m3))
			return true;
		return false;
	}
};