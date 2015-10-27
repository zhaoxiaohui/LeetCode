##
 #	 Description: 
 #	      Author: zhaoxiaohui
 #	        Site: zhaoxiaohui.sinaapp.com
 #	        Date: 2014
 ##

class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        """
        :type nums: List[int]
        :type k: int
        :type t: int
        :rtype: bool
        """
        if t < 0:
            return False
        table = {}
        t = t + 1
        for i in xrange(len(nums)):
            if i > k:
                del table[nums[i - k - 1] / t]
            m = nums[i] / t
            if m in table:
                return True
            if m - 1 in table and abs(nums[i] - nums[table[m - 1]]) < t:
                return True
            if m + 1 in table and abs(nums[i] - nums[table[m + 1]]) < t:
                return True
            table[m] = i
        return False
