/**
 *	 Description: https://leetcode.com/problems/find-the-duplicate-number/
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2015-12-23
 * 
 *          O(N): http://keithschwarz.com/interesting/code/?dir=find-duplicate (Excellent)
 */

class Solution {
public:
	int findDuplicateBin(vector<int> &nums) {
		int low = 1;
    	int high = nums.size() - 1;
    	int mid, count;
    	while (low < high) {
    		mid = (low + high) / 2;
    		count = 0;
    		for (int i = 0; i < nums.size(); i++) {
    			if (nums[i] <= mid) {
    				count++;
    			}
    		}
    		if (count <= mid) {
    			low = mid + 1;
    		} else {
    			high = mid;
    		}
    	}
    	return low;
	}
	int findDuplicateCircle(vector<int> &nums) {
		int slow = nums.size() - 1;
		int fast = nums.size() - 1;
		while (true) {
			slow = nums[slow] - 1;
			fast = nums[nums[fast] - 1] - 1;
			if (slow == fast) break;
		}
		int rebegin = nums.size() - 1;
		while (true) {
			slow = nums[slow] - 1;
			rebegin = nums[rebegin] - 1;
			if (slow == rebegin) return slow;
		}
	}
    int findDuplicate(vector<int>& nums) {
    	return findDuplicateCircle(nums);
    }
};