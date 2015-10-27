/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int numTrees(int n) {
		if(n<=2)return n;
		vector<int> numbers(n+1, 0);
		numbers[0] = 1;
		numbers[1] = 1;
		numbers[2] = 2;
		for(int i=3;i<=n;i++){
			for(int root=1;root<=i;root++){
				numbers[i] += numbers[root-1]*numbers[i-root];
			}
		}
		return numbers[n];
	}
};