/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
		bool find = false;
		solveSudokuUtil(board, 0 , find);
	}
	void solveSudokuUtil(vector<vector<char> > &board, int deep, bool &find){
		if(find)return;
		if(deep >80){
			find = true;
			return;
		}
		int r = deep/9,c=deep%9;
		if(board[r][c] != '.'){
			solveSudokuUtil(board, deep+1, find);
		}else{
			vector<bool> available(9, true);
			getAvailable(deep/9, deep%9, board, available);
			for(int i=0;i<9;i++){
				if(available[i]){
					board[r][c] = i+'1';
					solveSudokuUtil(board,deep+1, find);
					if(find)return;
					board[r][c] = '.';
				}
			}
		}
		
	}
	void getAvailable(int r, int c, vector<vector<char> > board, vector<bool> &available){
		//check row
		for(int i=0; i<9;i++){
			if(board[r][i] !='.')
				available[board[r][i]-'1'] = false;
		}
		//check col
		for(int i=0;i<9;i++){
			if(board[i][c] !='.')
				available[board[i][c]-'1'] = false;
		}

		int x = (r  / 3) * 3;
		int y = (c  / 3) * 3;/// 3 * 3;
		for (int i = x; i < x+3; i++){
			for (int j = y; j< y+3; j++){
				if (board[i][j] != '.') 
					available[board[i][j]-'1'] = false;
			}
		}
	}
};