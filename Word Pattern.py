##
 #	 Description: 
 #	      Author: zhaoxiaohui
 #	        Site: zhaoxiaohui.sinaapp.com
 #	        Date: 2014
 ##

class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        words = str.split(" ")
        if len(words) != len(pattern):
            return False
        maps = {}
        ind = 0
        for w in pattern:
            if w not in maps:
                maps[w] = words[ind]
            else:
                if maps[w] != words[ind]:
                    return False
            ind = ind + 1
        maps = {}
        ind = 0
        for w in words:
            if w not in maps:
                maps[w] = pattern[ind]
            else:
                if maps[w] != pattern[ind]:
                    return False
            ind = ind + 1
        return True
