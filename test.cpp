#include <vector>
#include <iostream>
#include "Find Minimum in Rotated Sorted Array II.cpp"
using namespace std;
/**
 *	 Description: Run the Classes
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2015-
 */

 

 int main(int argc, char *argv[]) {

 	Solution s;
 	std::vector<int> v;
 	int k, t;
 	v.push_back(4);
 	v.push_back(5);
 	v.push_back(6);
 	v.push_back(7);
 	v.push_back(0);
 	v.push_back(1);
 	v.push_back(2);
 	cout<<s.findMin(v)<<endl;
 }