/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

struct NUM_MAP{
	int num;
	int ind;
	NUM_MAP(){}
	NUM_MAP(int n, int i):num(n), ind(i){}
};
bool cmp(NUM_MAP a, NUM_MAP b){
	return a.num < b.num;
}
class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		int n = numbers.size();
		NUM_MAP num_map[n];
		for(int i=0;i<n;i++){
			num_map[i].num = numbers[i];
			num_map[i].ind = i+1;
		}
		sort(num_map, num_map+n, cmp);
		int left = 0, right = n-1, sum;
		vector<int> ret;
		while(left<right){
			sum = num_map[left].num + num_map[right].num;
			if(sum > target){
				right--;
			}else if(sum < target){
				left++;
			}else{
				ret.push_back(min(num_map[left].ind, num_map[right].ind));
				ret.push_back(max(num_map[left].ind, num_map[right].ind));
				return ret;
			}
		}
		return ret;
	}
};
