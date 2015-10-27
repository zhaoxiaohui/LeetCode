/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) 
	{
		vector<vector<string> > ret;
		int *pos = new int[n];
		totalNQueensUtil(ret, pos, 0, 0, 0, 0, n);
		delete [] pos;
		return ret;
	}
	void totalNQueensUtil(vector<vector<string> > &ret,int *pos, int row, int maskrow, int maska1, int maska2,  int rows){
		if(row == rows){
			//ret++;
			vector<string> ones;
			char onewrow[rows];
			memset(onewrow,'.', sizeof(char)*rows);
			for(int i=0;i<rows;i++){
				onewrow[pos[i]] = 'Q';
				string str(onewrow, rows);
				ones.push_back(str);
				onewrow[pos[i]] = '.';
			}
			ret.push_back(ones);
			return;
		}
		int po = 1, m1, m2, m3;
		for(int i=0;i<rows;i++){
			po <<= 1;
			m1 = po, m2 = 1<<(row+i), m3 = 1<<(rows-1+row-i);
			if( check(m1, m2, m3, maskrow, maska1, maska2) ){
				pos[row] = i;
				totalNQueensUtil(ret, pos,row+1, maskrow | m1, maska1 | m2, maska2 | m3, rows);
			}
		}
	}

	bool check(int m1, int m2, int m3, int mask1, int mask2, int mask3){
		if(((m1 ^ mask1) & m1) && ((m2 ^ mask2) & m2) && ((m3 ^ mask3) & m3))
			return true;
		return false;
	}
};