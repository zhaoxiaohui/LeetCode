/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
		if(word.length() == 0)return true;
		int rows = board.size();
		if(rows == 0)return false;
		int cols = board[0].size();
		bool find = false;
		bool **used =  new bool*[rows];
		for(int i=0;i<rows;i++){
			used[i] = new bool[cols];
			memset(used[i], false, sizeof(bool)*cols);
		}
		//find the start position
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				if(board[i][j] == word[0]){
					used[i][j] = true;
					DFS(board,rows,cols,i,j,1,word,used,find);
					if(find)break;
					used[i][j] = false;
				}
			}
			if(find)break;
		}
		return find;
	}

	void DFS(vector<vector<char> > &board, int rows, int cols, int pox,int poy, int deep, string word, bool **used,bool &find){
		if(find)return;
		if(deep == word.length()){
			find = true;
			return;
		}
		int dir[][2] = {{1,0},{0,1},{-1, 0},{0,-1}};
		int nextx,nexty;
		for(int d=0;d<4;d++){
			nextx = pox+dir[d][0];
			nexty = poy+dir[d][1];
			if(nextx>=0 && nextx<rows && nexty>=0 && nexty<cols && !used[nextx][nexty] && board[nextx][nexty]==word[deep]){
				used[nextx][nexty] = true;
				DFS(board,rows, cols, nextx, nexty, deep+1, word, used, find);
				if(find)break;
				used[nextx][nexty] = false;
			}
		}
	}
};