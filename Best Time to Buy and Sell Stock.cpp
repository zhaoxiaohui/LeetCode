/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
		int len = prices.size();
		if(len == 0)return 0;
		int curMin;//当前最小点
		int hisMin;//历史最小点-一次交易之前的最小点
		int curMax=-1;
		int ret = 0;
		curMin = hisMin = prices[0];
		for(int i=1;i<len;i++){
			if(prices[i]>prices[i-1]){
				curMax = prices[i];
			}else{
				if(curMax != -1){
					hisMin = min(hisMin, curMin);
					//hisMax = max(hisMax, curMax);
					ret = max(ret, curMax-hisMin);
					curMax = -1;
				}
				curMin = prices[i];
			}
		}
if(curMax != -1){
			hisMin = min(hisMin, curMin);
			//hisMax = max(hisMax, curMax);
			ret = max(ret, curMax-hisMin);
			curMax = -1;
		}
		return ret;
	}
};