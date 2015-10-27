/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int removeDuplicates(int A[], int n) {
		int skip =0;
		int count = 1;
		for(int i=1;i<n;i++){
			if(A[i]==A[i-1]){
				count++;
				if(count>2)skip++;
				else{
					A[i-skip] = A[i];
				}
			}else{
				count = 1;
				A[i-skip] = A[i];
			}
		}
		return n-skip;
	}
};