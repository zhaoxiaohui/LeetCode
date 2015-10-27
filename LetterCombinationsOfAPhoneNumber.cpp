/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    vector<string> letterCombinations(string digits) {
		vector<string> res;
		if(digits.length() ==0){
			res.push_back("");
			return res;
		}
		map<char, string> numbers;
		numbers['2'] = "abc";
		numbers['3'] = "def";
		numbers['4'] = "ghi";
		numbers['5'] = "jkl";
		numbers['6'] = "mno";
		numbers['7'] = "pqrs";
		numbers['8'] = "tuv";
		numbers['9'] = "wxyz";
		int each = 0, tempeach = 0;
		each = numbers[digits[0]].length();
		queue<string> qs;
		for(int i=0;i<each;i++)
			qs.push(numbers[digits[0]].substr(i,1));
		int ind = 1;
		string top;
		while(ind<digits.length()){
			tempeach = 0;
			while(each--){
				top = qs.front();
				qs.pop();

				for(int i=0;i<numbers[digits[ind]].length();i++){
					string str = top;
					str.append(numbers[digits[ind]].substr(i,1));
					tempeach++;
					qs.push(str);
				}
			}
			each = tempeach;
			ind++;
		}
		while(!qs.empty()){
			res.push_back(qs.front());
			qs.pop();
		}
		return res;
	}
};
