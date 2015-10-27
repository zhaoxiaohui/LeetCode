/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
		return searchRange_2(A, n, target);
	}
	vector<int> searchRange_2(int A[], int n, int target){
		int m = binarySearch(A, 0, n-1, target);
		int left, right, retl=-1, retr=-1;
		if(m != -1){
			left = right = retl= retr = m;
			while((left = binarySearch(A, 0, left-1,target)) !=-1){retl = left;}
			while((right = binarySearch(A,right+1, n-1, target)) != -1){retr = right;}
		}
		vector<int> ret;
		ret.push_back(retl);
		ret.push_back(retr);
		return ret;
	}
	int binarySearch(int A[], int l,int r, int target){
		int m;
		while(l<=r){
			m = l + (r-l)/2;
			if(A[m]==target)
				return m;
			if(A[m]<target)
				l = m+1;
			else
				r = m-1;
		}
		return -1;
	}

	vector<int> searchRange_1(int A[], int n, int target){
		int find = binarySearch(A, 0, n-1, target);
		int retl, retr;
		if(find != -1){
			retl = retr = find;
			while(retl-1 >=0 && A[retl-1]==target){retl--;}
			while(retr+1 <n && A[retr+1]==target){retr++;}
		}
		vector<int> ret;
		ret.push_back(retl);
		ret.push_back(retr);
		return ret;
	}
};