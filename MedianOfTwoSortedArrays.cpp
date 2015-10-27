/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m+n;
        if(total % 2 == 0) {
            return (double)(findKthSortedArrays(A, m, B, n, total/2) + findKthSortedArrays(A, m, B, n, total/2 + 1)) / 2;
        } else {
            return (double)findKthSortedArrays(A, m, B, n, total/2 + 1);
        }
    }

    int findKthSortedArrays(int A[], int m, int B[], int n, int k) {
        int mi = (int)(1.0*m / (m+n) * (k-1));
        int ni = k-1-mi;

        int Ai_1  = mi <= 0    ? INT_MIN:A[mi-1];
        int Ai    = mi >= m    ? INT_MAX:A[mi];
        int Bj_1  = ni <= 0    ? INT_MIN:B[ni-1];
        int Bj    = ni >= n    ? INT_MAX:B[ni];

        //Ai-1<Bj<Ai
        if(Ai_1 <= Bj && Bj <= Ai){
            return Bj;
        }
        //Bj-1<Ai<Bj
        if(Bj_1 <= Ai && Ai <= Bj){
            return Ai;
        }
        //Ai<Bj
        if(Ai < Bj)
            return findKthSortedArrays(A+mi+1, m - mi - 1, B, ni, k - mi - 1);
        //Bj<Ai
        else return findKthSortedArrays(A, mi, B+ni+1, n - ni - 1, k - ni - 1);
    }
};
