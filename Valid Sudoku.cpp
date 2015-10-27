/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
		bool avail_r[9][9];
		bool avail_c[9][9];
		memset(avail_r, true, sizeof(bool)*81);
		memset(avail_c, true, sizeof(bool)*81);
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				if(board[i][j]!='.'){
					if(!avail_r[i][board[i][j]-'1'])return false;
					avail_r[i][board[i][j]-'1'] = false;
					if(!avail_c[j][board[i][j]-'1'])return false;
					avail_c[j][board[i][j]-'1'] = false;
				}
			}
		}
		bool avail[9];
		for(int i=0;i<9;i+=3){
			for(int j=0;j<9;j+=3){
				memset(avail, true, sizeof(avail));
				for(int x=i;x<i+3;x++){
					for(int y=j;y<j+3;y++){
						if(board[x][y]!='.'){
							if(!avail[board[x][y]-'1'])return false;
							avail[board[x][y]-'1'] = false;
						}
					}
				}
			}
		}
		return true;
	}
};