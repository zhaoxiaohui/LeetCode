/**
 *	 Description: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2015-11-19
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
    	int left = 0, right = nums.size() - 1, mid;
    	while (left < right) {
    		mid = (left + right) / 2;
    		if (nums[mid] > nums[right]) { //left is ordered
    			if (nums[left] < nums[right]) return nums[left];
    			else left = mid + 1;
    		} else { //right is ordered
    			if (nums[left] < nums[right]) return nums[left];
    			else right = mid;
    		}
    	}
    	return nums[left];
    }
};