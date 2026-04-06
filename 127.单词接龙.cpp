/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    unordered_map<string, int> wordId;
    vector<vector<int>> edge;
    int nodeNum = 0;

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // return bfsSolution(beginWord, endWord, wordList);
        return leetcodeSolution(beginWord, endWord, wordList);
    }

    void addWord(string& word) {
        if (!wordId.count(word)) {
            wordId[word] = nodeNum++;
            edge.emplace_back();
        }
    }

    void addEdge(string& word) {
        addWord(word);
        int id1 = wordId[word];
        for (char& it : word) {
            char tmp = it;
            it = '*';
            addWord(word);
            int id2 = wordId[word];
            edge[id1].push_back(id2);
            edge[id2].push_back(id1);
            it = tmp;
        }
    }

    int leetcodeSolution(string beginWord, string endWord, vector<string>& wordList) {
        for (string& word : wordList) {
            addEdge(word);
        }
        addEdge(beginWord);
        if (!wordId.count(endWord)) {
            return 0;
        }
        vector<int> dis(nodeNum, INT_MAX);
        int beginId = wordId[beginWord], endId = wordId[endWord];
        dis[beginId] = 0;

        queue<int> que;
        que.push(beginId);
        while (!que.empty()) {
            int x = que.front();
            que.pop();
            if (x == endId) {
                return dis[endId] / 2 + 1;
            }
            for (int& it : edge[x]) {
                if (dis[it] == INT_MAX) {
                    dis[it] = dis[x] + 1;
                    que.push(it);
                }
            }
        }
        return 0;
    }

    // 在线无法通过 test case 51 "oar" "set"
    // 但是本地测试，test case 51 可以通过
    int bfsSolution(string& beginWord, string& endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> adj;

        for(string& w : wordList) {
            if (isEdge(beginWord, w)) {
                adj[beginWord].push_back(w);
            }
        }

        for(string& w1 : wordList) {
            if (adj.find(w1) != adj.end()) continue;

            for(string& w2 : wordList) {
                if(isEdge(w1, w2)) {
                    adj[w1].push_back(w2);
                }
            }
        }

        if (adj.find(endWord) == adj.end()) {
            return 0;
        }

        queue<string> qu;
        qu.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);

        int ans = 1;
        while (!qu.empty())
        {
            int n = qu.size();
            for(int i = 0; i < n; ++i) {
                string s = qu.front();
                qu.pop();

                for(string& w : adj[s]) {
                    if (w == endWord) {
                        return ans+1;
                    } else if (visited.find(w) == visited.end()) {
                        qu.push(w);
                        visited.insert(w);
                    }
                }
            }
            ans++;
        }

        return 0;
    }

    bool isEdge(string& w1, string& w2) {
        int n = 0;
        for(int i = 0; i < w1.length(); ++i) {
            if (w1[i] != w2[i]) {
                n++;
                if (n > 1) {
                    return false;
                }
            }
        }
        return n == 1;
    }
};
// @lc code=end

