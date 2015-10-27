/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		vector<vector<int> > ret;
		int n = num.size();
		for(int l=0; l< n-3; l++){
			while(l && num[l] == num[l-1])l++;
			for(int lm=l+1;lm<n-2;lm++){
				while(lm!=l+1 && num[lm] == num[lm-1])lm++;
				int rm = lm+1, r = n-1;
				while(rm < r){
					int sum = num[l] + num[lm] + num[rm] + num[r];
					if(sum > target){
						r--;
						while(rm < r && num[r] == num[r+1])r--;
					}else if(sum < target){
						rm++;
						while(rm < r && num[rm] == num[rm-1])rm++;
					}else{
						vector<int> one;
						one.push_back(num[l]);
						one.push_back(num[lm]);
						one.push_back(num[rm]);
						one.push_back(num[r]);
						ret.push_back(one);
						rm++;
						while(rm < r && num[rm] == num[rm-1])rm++;
					}
				}
			}
		}
		return ret;
    }
};
