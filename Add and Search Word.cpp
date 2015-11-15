/**
 *   Description: https://leetcode.com/problems/add-and-search-word-data-structure-design/
 *        Author: zhaoxiaohui
 *          Site: zhaoxiaohui.sinaapp.com
 *          Date: 2015-11-15
 */

struct TireNode {
    TireNode *children[26];
    string word;
    TireNode() {
        memset(children, 0, sizeof(TireNode *) * 26);
        word = "";
    }
};

class WordDictionary {
public:
    TireNode *root;
    WordDictionary() {
        root = new TireNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        const char *str = word.c_str();
        TireNode *cur_node = root;
        while(*str) {
            if (cur_node->children[*str - 'a'] == NULL) {
                cur_node->children[*str - 'a'] = new TireNode();
            }
            cur_node = cur_node->children[*str - 'a'];
            str++;
        }
        cur_node->word = word;
    }
    bool match(const char *str, int deep, int len, TireNode *cur_node) {
        if (deep == len) {
            return !cur_node->word.empty();;
        }
        if (*str != '.') {
            return cur_node->children[*str - 'a'] && match(str + 1, deep + 1, len, cur_node->children[*str - 'a']);
        } else {
            for (int i = 0; i < 26; i++) {
                if (cur_node->children[i] && match(str + 1, deep + 1, len, cur_node->children[i])) {
                    return true;
                }
            }
            return false;
        }
    }
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return match(word.c_str(), 0, word.length(), root);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");