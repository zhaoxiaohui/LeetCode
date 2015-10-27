/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
   int numDistinct(string S, string T) {
		int m = T.length();
		int n = S.length();
		vector<vector<int>> path(m+1, vector<int>(n+1, 0));
		for(int j=0;j<n;j++){
			if(T[0]==S[j])path[0][j] = 1;
		}
		for(int j=1;j<=n;j++){
			for(int i=1;i<=m;i++){
				path[i][j] = path[i][j-1] + (T[i-1]==S[j-1]?path[i-1][j-1]:0);
			}
		}
		return path[m][n];
	}
};