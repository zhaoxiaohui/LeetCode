/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        for(int i=1;i<triangle.size();i++){
            for(int j=0;j<=i;j++){
                if(j==0)triangle[i][j] = triangle[i-1][j]+triangle[i][j];
                else if(j==i)triangle[i][j] = triangle[i-1][j-1]+triangle[i][j];
                else triangle[i][j] = min(triangle[i][j]+triangle[i-1][j-1], triangle[i][j]+triangle[i-1][j]);
            }
        }
        int res = 0x7FFFFFFF, last = triangle.size()-1;
        for(int i=0;i<triangle.size();i++)
            if(res > triangle[last][i])
                res = triangle[last][i];
        return res;
    }
};