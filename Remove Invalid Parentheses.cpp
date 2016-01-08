/**
 *	 Description: https://leetcode.com/problems/remove-invalid-parentheses/
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2015-1-8
 */

class Solution {
public:
	bool validParenthese(const string &cur_str) {
		stack<char> parenthese;
		for (int i = 0; i < cur_str.length(); i++) {
		    if (cur_str[i] != ')' && cur_str[i] != '(' ) continue;
			if (cur_str[i] == ')' && !parenthese.empty() && parenthese.top() == '(') {
				parenthese.pop();
			} else {
				parenthese.push(cur_str[i]);
			}
		}
		return parenthese.empty();
	}
	void removeInvalidParenthesesStatelessDFS(set<string> &ret, const char *str, string cur_str, int ind, int deep, int rcount, int &minr, int len) {
		if (minr != -1 && rcount > minr) return;
		if (deep == len) {
			if (validParenthese(cur_str)) {
				minr = rcount;
				ret.insert(cur_str);
			}
			return;
		}
		// with it
		removeInvalidParenthesesStatelessDFS(ret, str, cur_str + string(1, str[ind]), ind + 1, deep + 1, rcount, minr, len);
		// trick
		// skip the same ....same char remove one is enough as it will generate the same str
		int step = 1;
		while (ind - 1 >= 0 && str[ind] == str[ind - 1]) ind--, step++;
		// without it
		removeInvalidParenthesesStatelessDFS(ret, str, cur_str, ind + step, deep + 1, rcount + 1, minr, len);
	}
	string removeInvalidParenthesesBeforeAndBack(string &s) {
		string ret = "";
		int b = 0, e = s.length() - 1;
		for (; b <= e; b++) {
			if (s[b] == '(') break;
			if (s[b] != ')') ret += string(1, s[b]);
		}
		string rev_ret = "";
		for (; e >= b; e--) {
			if (s[e] == ')') break;
			if (s[e] != '(') rev_ret += string(1, s[e]);
		}
        reverse(rev_ret.begin(), rev_ret.end());
		return ret + s.substr(b, e - b + 1) + rev_ret;
	}
	// 882ms slow slow slow
	vector<string> removeInvalidParenthesesStateless(string s) {
		vector<string> ret;
  		set<string> sret;
  		if (s.length() != 0) {
  			int minr = -1;
  			s = removeInvalidParenthesesBeforeAndBack(s); // trick
  			removeInvalidParenthesesStatelessDFS(sret, s.c_str(), "", 0, 0, 0, minr, s.length());
  		} else {
  		    sret.insert("");
  		}
  		copy(sret.begin(), sret.end(), back_inserter(ret));
  		return ret;
	}
	// match is perfect, do not need to check is valid parenthese
	void removeInvalidParenthesesStateDFS(unordered_set<string> &sret, string &s, string cur, int ind, int l_remain, int r_remain, int match) {
		if (ind == s.length()) {
			if (l_remain == 0 && r_remain == 0 && match == 0) {
				sret.insert(cur);
			}
			return;
		}
		if (s[ind] != ')' && s[ind] != '(') {
			removeInvalidParenthesesStateDFS(sret, s, cur + s[ind], ind + 1, l_remain, r_remain, match);
		} else {
			if (s[ind] == '(') {
				if (l_remain > 0) {
					removeInvalidParenthesesStateDFS(sret, s, cur, ind + 1, l_remain - 1, r_remain, match);
				}
				removeInvalidParenthesesStateDFS(sret, s, cur + s[ind], ind + 1, l_remain, r_remain, match + 1);
			} else {
				if (r_remain > 0) {
					removeInvalidParenthesesStateDFS(sret, s, cur, ind + 1, l_remain, r_remain - 1, match);
				}
				if (match > 0) // come after left
					removeInvalidParenthesesStateDFS(sret, s, cur + s[ind], ind + 1, l_remain, r_remain, match - 1);
			}
		}
	}
	// fast fast fast
	vector<string> removeInvalidParenthesesState(string s) {
		int l_remain = 0, r_remain = 0;
		for (auto c : s) {
			if (c == '(') l_remain++;
			else if (c == ')'){
				if (l_remain != 0) l_remain--;
				else r_remain++;
			}
		}
		unordered_set<string> sret;
		removeInvalidParenthesesStateDFS(sret, s, "", 0, l_remain, r_remain, 0);
		return vector<string>(sret.begin(), sret.end());

	}
    vector<string> removeInvalidParentheses(string s) {
    	//return removeInvalidParenthesesStateless(s);
    	return removeInvalidParenthesesState(s);
    }
};