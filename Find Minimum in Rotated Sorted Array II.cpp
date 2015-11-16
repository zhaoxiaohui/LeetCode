/**
 *	 Description: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2015-11-16
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
    	int left = 0, right = nums.size() - 1, mid;
    	while (left < right) {
    		if (nums[left] == nums[right]) {
    			while (nums[left] == nums[left + 1] && left + 1 <= right) left++;
    			while (nums[right] == nums[right - 1] && right -1 >= left) right--;
    		}
    		if (left == right) {
    			return nums[left];
    		}
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