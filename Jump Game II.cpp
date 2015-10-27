/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int jump(int A[], int n) {
		if(n<=1)return 0;
		int *dp = new int[n];
		memset(dp, 0, sizeof(int)*n);
		int minStep;
		for(int i=n-2;i>=0;i--){
			minStep = 0x7FFFFFFF;
			if((i+1+A[i])>=n){
				dp[i] = 1;
				continue;
			}
			for(int j=A[i];j>=1;j--){
				minStep = min(minStep,dp[i+j]);
				if(minStep ==1)break;
			}
			dp[i] = minStep==0x7FFFFFFF?minStep:minStep+1;
		}
		return dp[0];
	}
};