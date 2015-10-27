/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int removeDuplicates(int A[], int n) {
		if(n==1)return n;
		int removeCount = 0;
		for(int i=1;i<n;i++){
			if(A[i]!=A[i-1]){
				A[i-removeCount] = A[i];
			}else removeCount++;
		}
		return n-removeCount;
	}
};
