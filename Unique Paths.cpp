/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
		if(m==1 || n==1)return 1;
		int *row = new int[n];
		row[0] = 0;
		for(int i=1;i<n;i++){
			row[i] = 1;
		}
		int j = 1;
		while(j<m){
			row[0] =1;
			for(int i=1;i<n;i++){
				row[i] = row[i-1]+row[i];
			}
			j++;
		}
		return row[n-1];
	}
};