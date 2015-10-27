/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
   map<int, string> numbers;
	Solution(){
		//I(1)£¬V(5)£¬X(10)£¬L(50)£¬C(100)£¬D(500)£¬M(1000)
		numbers[1] = "I";
		numbers[5] = "V";
		numbers[10] = "X";
		numbers[50] = "L";
		numbers[100] = "C";
		numbers[500] = "D";
		numbers[1000] = "M";
	}
	string intToRoman(int num) {
		return intToRoman3(num);
	}
	string intToRoman3(int num){
		int index=1, cur;
		string res = "";
		while(num){
			cur = num % 10;
			switch(cur){
			case 1:case 2:case 3:
				for(int i=0;i<cur;i++)
					res.append(numbers[index]);
				break;
			case 4:
				res.append(numbers[index*5]+numbers[index]);
				break;
			case 5:
				res.append(numbers[index*5]);
				break;
			case 6:case 7:case 8:

				for(int i=5;i<cur;i++){
					res.append(numbers[index]);
				}
				res.append(numbers[index*5]);
				break;
			case 9:
				res.append(numbers[index*10] +numbers[index]);
				break;
			}
			num /= 10;
			index *= 10;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
