/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
   void sortColors(int A[], int n) {
		int pre=0, ind, tail=n-1;
		while(pre<n && A[pre]==0)pre++;
		while(tail>=0 && A[tail]==2)tail--;
		ind = pre;
		while(ind <= tail){
			if(A[ind]==2){
				swap(A[ind], A[tail]);
				while(tail>=0 && A[tail]==2)tail--;
			}else if(A[ind]==0){
				swap(A[ind], A[pre]);
				while(pre<n && A[pre]==0)pre++;
				if(ind<pre)ind = pre;
			}else{
				ind++;
			}
		}
	}
};