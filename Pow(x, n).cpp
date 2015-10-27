/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    double pow(double x, int n) {
		// power of 0
		if (n == 0){
			return 1;
			// negative exponenet
		}else if( n < 0){
			if(n==INT_MIN)return 1 / x * pow(x, -(n+1));
			return 1 / pow(x, -n);
			// even exponenet
		}else if ((int)n % 2 == 0){
			double half_pow = pow(x, n/2);
			return half_pow * half_pow;
			//integer exponenet
		}else{
			return x * pow(x, n - 1);
		}
	}
};