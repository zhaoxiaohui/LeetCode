/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
		int ind = 0;
		while(ind<n){
			if(A[ind] == elem){
				if(n-1 != ind){
					A[ind] ^= A[n-1];
					A[n-1] ^= A[ind];
					A[ind] ^= A[n-1];
				}
				n--;
			}else ind++;
		}
		return n;
	}
};