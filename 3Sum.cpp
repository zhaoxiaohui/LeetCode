/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > ret;
        vector<int> row(3);
        int len = num.size();
        int low, high, cursum;
        for(int i=0; i<len; ++i) {
            while(i>0 && num[i]==num[i-1])++i;
            low = i+1, high = len-1;
            while(low < high) {
                cursum = num[i] + num[low] + num[high];
                if(cursum == 0){
                    row[0] = num[i];
                    row[1] = num[low];
                    row[2] = num[high];
                    ret.push_back(row);
                    ++low;
                    while(low < high && num[low] == num[low-1])++low;
                }else if(cursum > 0){
                    --high;
                    while(low < high && num[high] == num[high+1])--high;
                }else {
                    ++low;
                    while(low < high && num[low] == num[low-1])++low;
                }
            }
        }
        return ret;
    }
};
