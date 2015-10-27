/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
		int ind = m+n-1;
		int ida = m-1,idb = n-1;
		while(ida>=0 && idb>=0){
			if(A[ida]>B[idb]){
				A[ind--] = A[ida--];
			}else{
				A[ind--] = B[idb--];
			}
		}
		while(ida>=0){
			A[ind--] = A[ida--];
		}
		while(idb>=0){
			A[ind--] = B[idb--];
		}
	}
};