/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int search(int A[], int n, int target) {
		return searchUtil(A, 0, n-1, target);
	}
	int searchUtil(int A[], int l, int r, int target){
		if(l > r)return -1;
		int mid = (r-l)/2 + l;
		if(A[mid] == target)return mid;
		if(A[l] <= A[mid]){//left is ordered
			if(A[l] <= target && A[mid]>target)return searchUtil(A, l, mid-1, target);
			else return searchUtil(A, mid+1, r, target);
		}else{ // right is ordered
			if(A[r]>= target && A[mid]<target)return searchUtil(A, mid+1, r, target);
			else return searchUtil(A, l, mid-1, target);
		}
	}
};