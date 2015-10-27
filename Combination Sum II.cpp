/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		int len = num.size();
		vector<vector<int> > ret;
		vector<int> curret;
		//start with
		for(int i=0;i<len;i++){
			if(i!=0 && num[i]==num[i-1]) {
				while(i<len && num[i] == num[i-1]){i++;}
			}
			if(i==len)break;
			curret.push_back(num[i]);
			combinationSum2Util(i+1,num[i],target, curret, ret, num);
			curret.pop_back();
		}
		return ret;
	}

	void combinationSum2Util(int deep, int cursum, int target, vector<int> curret, vector<vector<int> > &ret, vector<int> num){
		if(cursum>target)return;
		if(cursum == target){
			ret.push_back(curret);
			return;
		}
		if(deep >= num.size())return;
		//with
		curret.push_back(num[deep]);
		combinationSum2Util(deep+1,cursum+num[deep], target, curret,ret, num);
		//without
		//skip all the same
		int skip = 1;
		while(deep>0 && deep+skip<num.size() &&num[deep+skip]==num[deep+skip-1]){
			skip++;
		}
		curret.pop_back();
		combinationSum2Util(deep+skip, cursum, target, curret, ret, num);
	}
};