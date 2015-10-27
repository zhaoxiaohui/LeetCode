/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int rows = board.size();
        if(rows == 0)return;
        int cols = board[0].size();
        if(cols == 0)return;
        vector<vector<char>> isSurrounded(rows, vector<char>(cols, '0'));
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(board[i][j]=='O' && isSurrounded[i][j] == '0') {
                    flood(i, j, isSurrounded, board);
                }
            }
        }
    }
    void flood(int cx, int cy, vector<vector<char>> &isS, vector<vector<char>> &board) {
        int rows = board.size();
        int cols = board[0].size();
        bool goOut = false;
        if(cx==0 || cx==rows-1 || cy==0 || cy==cols-1)goOut = true;
        queue<int> indx;
        indx.push(cx);
        indx.push(cy);
        int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int curx, cury, nextx, nexty;
        while(!indx.empty()) {
            curx = indx.front();
            indx.pop();
            cury = indx.front();
            indx.pop();
            for(int d=0; d<4; d++) {
                nextx = curx + dir[d][0];
                nexty = cury + dir[d][1];
                if(nextx >= 0 && nextx<rows && nexty>=0 && nexty<cols && board[nextx][nexty]=='O' && isS[nextx][nexty]=='0') {
                    if(!goOut && (nextx == 0 || nextx == rows-1 || nexty==0 || nexty==cols-1) )goOut = true;
                    isS[nextx][nexty] = '1';
                    indx.push(nextx);
                    indx.push(nexty);
                }
            }
        }
        if(!goOut)floodFill(cx, cy, board);
    }
    void floodFill(int cx, int cy, vector<vector<char>> &board) {
        int rows = board.size();
        int cols = board[0].size();
        queue<int> indx;
        indx.push(cx);
        indx.push(cy);
        board[cx][cy] = 'X';
        int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int curx, cury, nextx, nexty;
        while(!indx.empty()) {
            curx = indx.front();
            indx.pop();
            cury = indx.front();
            indx.pop();
            for(int d=0; d<4; d++) {
                nextx = curx + dir[d][0];
                nexty = cury + dir[d][1];
                if(nextx >= 0 && nextx<rows && nexty>=0 && nexty<cols && board[nextx][nexty]=='O') {
                    board[nextx][nexty] = 'X';
                    indx.push(nextx);
                    indx.push(nexty);
                }
            }
        }
    }
};