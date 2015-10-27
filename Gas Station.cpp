/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int len = gas.size();
		for(int i=0;i<len;i++){
			gas[i] -= cost[i];
		}
		int maxGas = gas[0], sum = maxGas, ret=0;
		for(int i=1;i<len;i++){
			sum += gas[i];
			if(sum < maxGas){
				maxGas=sum;
				ret = i;
			}
		}
		return sum>=0?(ret+1)%len:-1;
	}
};