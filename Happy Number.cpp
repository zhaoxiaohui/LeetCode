/**
 *	 Description: https://leetcode.com/problems/happy-number/
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2015-11-19
 */

class Solution {
public:
  int get_ss(int n) {
    int ret = 0;
    while (n) {
      ret += pow(n % 10, 2);
      n /= 10;
    }
    return ret;
  }
    bool isHappy(int n) {
        unordered_set<int> trace;
      int st = get_ss(n);
      trace.insert(n);
      while (st != 1) {
            if (trace.find(st) != trace.end()) {
                break;
            }
            trace.insert(st);
        st = get_ss(st);
      }
      return st == 1 ? true : false;
    }
};