/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
        data.push(val);

        if (min_val.empty() || val <= min_val.top()) {
            min_val.push(val);
        }
    }
    
    void pop() {
        if (!min_val.empty() && data.top() == min_val.top())
            min_val.pop();
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min_val.top();
    }
private:
    stack<int> data, min_val;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

