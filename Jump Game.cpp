/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
   bool canJump(int A[], int n) {
		vector<bool> can(n, false);
		can[0] = true;
		int lastInd = 0, i, j;
		for(i=0;i<n;i++){
			if(can[i] && A[i] > 0 && ((lastInd+1) <= (i+A[i]))){
				for(j=lastInd+1; j<= (i+A[i]) && j<n; j++){
					can[j] = true;
				}
				lastInd = j-1;
			}
		}
		return can[n-1];
	}
};