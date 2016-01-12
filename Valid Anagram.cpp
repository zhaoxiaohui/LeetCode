/**
 *	 Description: https://leetcode.com/problems/valid-anagram/
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2015-1-12
 *
 *   Solution 2: using sort which can deal with the unicode (map is also accpted)
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        int num[2][26] = {0};
        for (auto c : s) num[0][c - 'a']++;
        for (auto c : t) num[1][c - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (num[0][i] != num[1][i]) return false;
        }
        return true;
    }
};