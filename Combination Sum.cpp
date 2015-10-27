/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int> > ret;
		vector<int> curret;
		combinationSumUtil(candidates,target,0,curret,ret,0);
		return ret;
	}

	void combinationSumUtil(vector<int> candidates, int target, int cursum, vector<int> curret, vector<vector<int> > &ret, int deep){
		if(cursum == target){
			ret.push_back(curret);
			return;
		}
		if(cursum>target)return;
		if(deep>=candidates.size())return;
	
		combinationSumUtil(candidates,target,cursum,curret, ret, deep+1);
		int loop = (target-cursum)/candidates[deep];
		for(int i=1;i<=loop;i++){
			curret.push_back(candidates[deep]);
			combinationSumUtil(candidates,target,cursum+candidates[deep]*i,curret, ret, deep+1);
		}
	}
};