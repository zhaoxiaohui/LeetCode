/**
 *	 Description: https://leetcode.com/problems/longest-increasing-subsequence/
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2015-1-5
 */

class Solution {
public:
	int lengthOfLISON2(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int len[nums.size()];
		len[0] = 1;
		int cur_maxlen = 1, maxlen = 1;
		for (int i = 1; i < nums.size(); i++) {
			cur_maxlen = 1;
			for (int j = 0; j < i; j++) {
				if (nums[j] < nums[i]) {
					cur_maxlen = max(cur_maxlen, len[j] + 1);
				}
			}
			len[i] = cur_maxlen;
			maxlen = max(maxlen, cur_maxlen);
		}
		return maxlen;
	}
	int lengthOfLISOLOGN(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		vector<int> small_longest{nums[0]};
		for (auto num : nums) {
			if (num > small_longest.back()) small_longest.push_back(num);
			else {
				int left = 0, right = small_longest.size() - 1;
				while (left < right) { // find lower bound where num > left and num <=right
					int mid = (left + right) / 2;
					if (small_longest[mid] >= num) right = mid; //have dulplicated nums
					else left = mid + 1;
				}
				small_longest[right] = num;
			}
		}
		return small_longest.size();
	}
    int lengthOfLIS(vector<int>& nums) {
        //return lengthOfLISON2(nums);
        return lengthOfLISOLOGN(nums);
    }
};