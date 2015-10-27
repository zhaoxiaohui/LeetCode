/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int m = obstacleGrid.size();
		if(m == 0)return 0;
		int n = obstacleGrid[0].size();
		if(n == 0)return 0;
		int *row = new int[n];
		//for the first row
		for(int i=0;i<n;i++){
			if(obstacleGrid[0][i] != 1)
				row[i] =1;
			else{
				while(i<n){
					row[i++] = 0;
				}
			}
		}
		int i=1,j=0;
		bool findOb = obstacleGrid[0][0]==1?true:false;
		while(i<m){
			if(!findOb && obstacleGrid[i][0] == 0){
				row[0] = 1;
			}else{
				findOb = true;
				row[0] = 0;
			}
			for(j=1;j<n;j++){
				if(obstacleGrid[i][j] == 0)
					row[j] += row[j-1];
				else row[j] = 0;
			}
			i++;
		}
		return row[n-1];
	}
};