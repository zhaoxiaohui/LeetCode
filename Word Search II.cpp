/**
 *	 Description: https://leetcode.com/problems/word-search-ii/
 *	      Author: zhaoxiaohui
 *	        Site: zhaoxiaohui.sinaapp.com
 *	        Date: 2015-1-21
 *
 */

struct Trie {
	Trie *child[26];
	char name;
	bool is_word;
	Trie(char n) : name(n), is_word(false) {
		memset(child, 0, sizeof(Trie *) * 26);
	}
};

class Solution {
private:
	Trie *root;
	void addWord(string& word) {
		if (word.size() == 0) return;
		Trie *root_it = root;
		int ind = 0;
		for (int i = 0; i < word.size(); i++) {
			ind = word[i] - 'a';
			if (root_it->child[ind] == NULL) {
				root_it->child[ind] = new Trie(word[i]);
			}
			root_it = root_it->child[ind];
		}
		root_it->is_word = true;
	}
	void generateTrie(vector<string>& words) {
		for (auto it = words.begin(); it != words.end(); it++) {
			addWord(*it);
		}
	}
	void findDFS(vector<vector<char>> &board, int h, int w, string path, Trie *node, 
		vector<vector<bool>> &visit, unordered_set<string> &res) {
		int ind = board[h][w] - 'a';
		if (node->child[ind] == NULL) {
			return;
		}
		if (node->child[ind]->is_word) {
			res.insert(path + board[h][w]);
		}
		int nh, nw;
		int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
		for (int d = 0; d < 4; d++) {
			nh = h + dir[d][0];
			nw = w + dir[d][1];
			if (nh >=0 && nh < board.size() && nw >=0 && nw < board[0].size() && !visit[nh][nw]) {
				visit[nh][nw] = true;
				findDFS(board, nh, nw, path + board[h][w], node->child[ind], visit, res);
				visit[nh][nw]  =false;
			}
		}
	}
	void findWords(vector<vector<char>> &board, unordered_set<string> &res) {
		int h = board.size();
		if (h == 0) return;
		int w = board[0].size();
		if (w == 0) return;
		vector<vector<bool>> visit(h, vector<bool>(w, false));
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				visit[i][j] = true;
				findDFS(board, i, j, "", root, visit, res);
				visit[i][j] = false;
			}
		}
	}
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        generateTrie(words);
        unordered_set<string> res;
        findWords(board, res);
        return vector<string>(res.begin(), res.end());
    }
    Solution() : root(new Trie('0')) {}
};