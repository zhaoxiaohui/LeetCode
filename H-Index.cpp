/**
 *	 Description: https://leetcode.com/problems/h-index/
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2015-12-21
 */

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        unsigned int N = citations.size();
        for (int i = 0; i < N; ++i) {
            if (N - i <= citations[i]) {
                return (N - i);
            }
        }
        return 0;
    }
};