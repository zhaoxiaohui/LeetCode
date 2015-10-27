/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int trap(int A[], int n) {
		if(n <= 1)return 0;
		int ret = 0;
		int leftInd = 0, solid = 0;
		for(int i=1;i<n;i++){
            if(A[i] >= A[leftInd]){
                ret += A[leftInd] * (i-leftInd -1) - solid;
                solid = 0;
                leftInd = i;
            }else{
                solid += A[i];
            }
		}//9 6 8 8 5 6 3
         //0 1 2 3 4 5 6
		if(leftInd != n-1){
            solid = 0;
            int rightInd = n-1;
            for(int i=n-2;i>=leftInd;i--){
                if(A[i] >= A[rightInd]){
                    ret += A[rightInd] * (rightInd-i-1) -solid;
                    solid = 0;
                    rightInd = i;
                }else{
                    solid += A[i];
                }
            }
		}
		return ret;
	}
};