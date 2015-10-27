/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
		vector<int> ret(rowIndex+1);
		ret[0]=1;
		int prej,t;
		for(int i=1;i<=rowIndex;i++){
			prej = 1;
			for(int j=1;j<=i;j++){
				if(j==i)ret[j] = 1;
				else{
					t = ret[j];
					ret[j] = ret[j]+prej;
					prej = t;
				}
			}
		}
		return ret;
	}
};