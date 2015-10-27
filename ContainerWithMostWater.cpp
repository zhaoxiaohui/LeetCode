/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int maxArea(vector<int> &height) {
		int ret = 0, left, right, curret, curhei;
		int len = height.size();
		for(left=0, right=len-1; left<right; ){
			if(height[left] > height[right]){
				curhei = height[right];
				curret = (right-left) * curhei;
				if(curret > ret){
					ret = curret;
				}
				while(left<right && height[right]<=curhei){right--;}
			}else{
				curhei = height[left];
				curret = (right-left) * curhei;
				if(curret > ret){
					ret = curret;
				}
				while(left<right && height[left]<=curhei){left++;}
			}

		}
		return ret;
	}
};
