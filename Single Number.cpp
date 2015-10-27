/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int singleNumber(int A[], int n) {
		if(n==0)return 0;
		int ret = A[0];
		for(int i=1;i<n;i++){
			ret ^= A[i];
		}
		return ret;
	}
};