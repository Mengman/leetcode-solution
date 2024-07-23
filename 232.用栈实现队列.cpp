/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        in2out();
        int x = out.top();
        out.pop();
        return x;
    }
    
    int peek() {
        in2out();
        return out.top();
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }
private:
    stack<int> in, out;
    
    void in2out() {
        if (out.empty()) {
            while (!in.empty()) {
                int x = in.top();
                in.pop();
                out.push(x);
            }
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

