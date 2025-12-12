/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
public:
    Trie() {
        memset(letters, NULL, sizeof(letters));
    }

    void insert(string word) {
        Trie* p = this;
        for(char ch : word) {
            char idx = ch - 'a';
            if (p->letters[idx] == nullptr) {
                p->letters[idx] = new Trie();
            }
            p = p->letters[idx];
        }
        p->isend = true;
    }
    
    bool search(string word) {
        Trie* p = this;
        for(char ch : word) {
            char idx = ch - 'a';
            if(p->letters[idx] == nullptr) {
                return false;
            } else {
                p = p->letters[idx];
            }
        }

        return p->isend;
    }
    
    bool startsWith(string prefix) {
        Trie* p = this;
        for(char ch : prefix) {
            char idx = ch - 'a';
            if(p->letters[idx] == nullptr) {
                return false;
            } else {
                p = p->letters[idx];
            }
        }
        return true;
    }

private:
    Trie* letters[26];
    bool isend = false;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

