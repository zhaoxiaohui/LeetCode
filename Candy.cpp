/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
	int candy(vector<int> &ratings) {
		return candy_1(ratings);
	}

	int candy_1(vector<int> &ratings){
		int len = ratings.size();
		if(len<=1)return len;
		int maxValue=0, maxIndex=0, ret=1, curCandy=1;
		for(int i=1;i<len;i++){
			if(ratings[i]>=ratings[i-1]){
				curCandy = ratings[i]==ratings[i-1]?1:curCandy+1;
				maxValue = curCandy;
				maxIndex = i;
			}else{
				if(curCandy==1){
					if(maxValue <= i-maxIndex){
						ret += i-maxIndex;
						maxValue++;
					}else{
						ret += i-maxIndex -1;
					}
				}
				curCandy = 1;
			}
			ret += curCandy;
		}
		return ret;
	}

	int candy_2(vector<int> &ratings){
		int len = ratings.size();
		if(len<=1)return len;
		int candys[len];
		for(int i=0;i<len;i++)
			candys[i] = 1;
		for(int i=1;i<len;i++){
			if(ratings[i]>ratings[i-1])
				candys[i] = candys[i-1]+1;
		}
		for(int i=len-2;i>=0;i--){
			if(ratings[i]>ratings[i+1] && candys[i]<=candys[i+1]){
				candys[i] = candys[i+1]+1;
			}
		}
		int res = 0;
		for(int i=0;i<len;i++)
			res += candys[i];
		return res;
	}
	
};