/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		int n = num.size();
		int left = 0, right, middle, dis, sum, ret_sum=INT_MAX, ret;
		while(left < n-2){
			middle = left + 1;
			right = n-1;
			while(middle < right){
				sum = num[left] + num[middle] + num[right];
				if(sum > target){
					right--;
					//ret_sum = min(abs(sum-target), ret_sum);
					if(ret_sum > abs(sum-target)){
						ret_sum = abs(sum-target);
						ret = sum;
					}
				}else if(sum < target){
					middle++;
					//ret = min(abs(sum-target), ret);
					if(ret_sum > abs(sum-target)){
						ret_sum = abs(sum-target);
						ret = sum;
					}
				}else return sum;
			}
			left++;
		}
		return ret;
    }
};
