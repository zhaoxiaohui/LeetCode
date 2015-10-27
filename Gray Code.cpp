/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    vector<int> grayCode(int n) {
		vector<int> ret;
		int up = pow(2, n);
		for(int i=0;i<up;i++){
			ret.push_back((i>>1) ^ (i));
		}
		return ret;
	}
};