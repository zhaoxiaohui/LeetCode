/**
 *	 Description: https://leetcode.com/problems/number-of-islands/
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2015-12-21
 */
class Solution {
public:
	// flood
	void flood(int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &visit) {
		int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
		queue<int> labels;
		labels.push(x);
		labels.push(y);
		visit[x][y] = true;
		int cur_x, cur_y, next_x, next_y;
		unsigned int height = grid.size();
		unsigned int width = grid[0].size();
		while (!labels.empty()) {
			cur_x = labels.front();
			labels.pop();
			cur_y = labels.front();
			labels.pop();
			for (int d = 0; d < 4; ++d) {
				next_x = cur_x + dir[d][0];
				next_y = cur_y + dir[d][1];
				if (next_x >= 0 && next_x < height && next_y >=0 && next_y < width 
				&& !visit[next_x][next_y] && grid[next_x][next_y] == '1') {
					labels.push(next_x);
					labels.push(next_y);
					visit[next_x][next_y] = true;
				}
			}
		}
	}
    int numIslands(vector<vector<char>>& grid) {
        unsigned int height = grid.size();
        if (height <= 0) {
        	return 0;
        }
        unsigned int width = grid[0].size();   
        vector<vector<bool>> visit(height, vector<bool>(width, 0));
        int island = 0;
        for (int h = 0; h < height; ++h) {
        	for (int w = 0; w < width; ++w) {
        		if (grid[h][w] == '1' && !visit[h][w]) {
        			++island;
        			flood(h, w, grid, visit);
        		}
        	}
        }
        return island;
    }
};