/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
		if(num.size()<2)return (int)num.size();
		unordered_map<int, int> hmap;
		int ret = 0;
		for(auto &val: num){
			if(hmap[val] != 0)continue;
			hmap[val] = 1;
			auto left = hmap[val-1], right = hmap[val+1];
			hmap[val-left] = hmap[val+right] = 1+left+right;
			ret = max(ret, 1+left+right);
		}
		return ret;
	}
};