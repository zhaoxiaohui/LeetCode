/**
 *	 Description: 
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2014
 */

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
		stack<int> nums;
		for(auto it = tokens.begin();it!=tokens.end();it++){
			if(isOperator(*it)){
				operate(nums, (*it)[0]);
			}else{
				nums.push(string2int(*it));
			}
		}
		return nums.top();
    }
	bool isOperator(string op){
		if(op=="+" || op=="-" || op=="/" || op=="*")return true;
		return false;
	}
	void operate(stack<int> &nums, char op){
		int op1,op2;
		op1 = nums.top();
		nums.pop();
		op2 = nums.top();
		nums.pop();
		switch(op){
		case '+':
			nums.push(op1+op2);
			break;
		case '-':
			nums.push(op2-op1);
			break;
		case '*':
			nums.push(op2*op1);
			break;
		case '/':
			nums.push(op2/op1);
			break;
		}
	}
	int string2int(string num){
		return atoi(num.c_str());
	}
};