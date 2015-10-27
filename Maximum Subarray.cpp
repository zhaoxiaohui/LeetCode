/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n==1)return A[0];
        int ret = A[0], cur = A[0];
        for(int i=1;i<n;i++){
            if(cur >= 0){
                cur += A[i];
            }else{
                cur = A[i];
            }
            ret = max(ret, cur);
        }
        return ret;
    }
};