/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
		int valley = INT_MAX, peak=INT_MIN;
		int len = prices.size();
		vector<int> hisPro(len, 0);
		vector<int> futPro(len, 0);
		int ret = 0;
		for(int i=0;i<len;i++){
			valley = min(valley, prices[i]);
			if(i>0){
				hisPro[i] = max(hisPro[i-1], prices[i]-valley);
			}
		}
		for(int i=len-1;i>=0;i--){
			peak = max(peak, prices[i]);
			if(i<len-1){
				futPro[i] = max(futPro[i+1], peak-prices[i]);
			}
		}
		for(int i=0;i<len;i++){
			ret = max(ret, hisPro[i]+futPro[i]);
		}
		return ret;
	}
};