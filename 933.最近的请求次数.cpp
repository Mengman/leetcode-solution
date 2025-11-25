/*
 * @lc app=leetcode.cn id=933 lang=cpp
 *
 * [933] 最近的请求次数
 */

// @lc code=start
class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        qu.push(t);
        while(qu.front() < t-3000) qu.pop();
        return qu.size();
    }
private:
    queue<int> qu;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end

