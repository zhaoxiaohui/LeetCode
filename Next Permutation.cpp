/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int curChange = -1, pre = 0, lastChange = -1;
        int len = num.size();
        for(int i=1; i<len; ++i) {
            if(num[pre] < num[i]) {
                curChange = pre;
                lastChange = i;
            }else if(curChange != -1 && num[i] > num[curChange]) {
                lastChange = i;
            }
            pre = i;
        }
        if(curChange == -1) sort(num.begin(), num.end());
        else {
            swap(num[curChange], num[lastChange]);
            sort(num.begin() + curChange + 1, num.end());
        }
    }
};