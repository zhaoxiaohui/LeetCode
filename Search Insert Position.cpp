/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
		int i;
		for(i=0;i<n;i++){
			if(A[i] >= target)return i;
		}
		return i;
	}
};