##
 #	 Description: 
 #	      Author: zhaoxiaohui
 #	        Site: zhaoxiaohui.sinaapp.com
 #	        Date: 2014
 ##

class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        table = {}
        for ind in range(0, len(nums)):
            if nums[ind] in table:
                if ind - table[nums[ind]] <= k:
                    return True
            table[nums[ind]] = ind;
        return False
