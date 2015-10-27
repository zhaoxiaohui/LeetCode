/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    string getPermutation(int n, int k) {
		string num, res;
		int total = 1;
		for (int i = 1; i <= n; ++i)
		{
			num.push_back(i + '0');
			total *= i;
		}
		k--;
		while (n)
		{
			total /= n;
			int i = k / total;
			k %= total;
			res.push_back(num[i]);
			num.erase(i, 1);
			n--;
		}
		return res;
	}
};