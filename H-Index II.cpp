/**
 *	 Description: https://leetcode.com/problems/h-index-ii/
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2015-12-21
 */

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int N = citations.size();
        int left = 0, right = N - 1;
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (citations[mid] == N - mid) {
                return N - mid;
            }
            if (N - mid < citations[mid] && (mid == 0 || (mid - 1 >= 0 && (N - mid + 1) > citations[mid - 1]))) {
                return N - mid;
            }
            if (N - mid > citations[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return 0;
    }
};