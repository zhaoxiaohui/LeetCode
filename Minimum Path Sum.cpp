/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
		int rows = grid.size();
		if(rows == 0)return 0;
		int cols = grid[0].size();
		if(cols == 0)return 0;
		vector<int> dist(cols, 0);
		dist[0] = grid[0][0];
		for(int i=1;i<cols;i++){
			dist[i] = dist[i-1] + grid[0][i];
		}
		for(int i=1;i<rows;i++){
			for(int j=0;j<cols;j++){
				if(j==0)dist[j] = dist[j] + grid[i][j];
				else dist[j] = min(dist[j], dist[j-1])+grid[i][j];
			}
		}
		return dist[cols-1];
	}
};