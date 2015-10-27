/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int singleNumber(int A[], int n) {
		int one=0, two=0, three;
		for(int i=0;i<n;i++){
			two |= one & A[i];
			one ^= A[i];
			three = two & one;
			one &= ~three;
			two &= ~three;
		}
		return one;
	}
};