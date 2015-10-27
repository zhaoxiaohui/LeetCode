/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if(len == 0 || s[0]=='0')return 0;
        vector<int> nums(len + 1);
        nums[0] = 1, nums[1] = 1;
        for(int i=1; i<len; ++i){
            if((s[i-1]=='1' && s[i]!='0') || (s[i-1]=='2' && (s[i]>='1' && s[i]<='6')))nums[i+1] = nums[i] + nums[i-1];
            else if(s[i-1]!='1' && s[i-1]!='2' && s[i]=='0')return 0;
            else if(s[i]=='0')nums[i+1] = nums[i-1]==0?1:nums[i-1];
            else nums[i+1] = nums[i];
        }
        return nums[len];
    }
};