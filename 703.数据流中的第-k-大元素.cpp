/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 */

// @lc code=start
class KthLargest
{
// 维护一个大小为 K 的小根堆 priority_queue
// priority_queue.top 就是第K个大的元素
// 每次添加新元素 add(val), 先检查 val 是否大于 prioprity_queue.top
// 如果大于，就将堆顶的元素出队列，然后再插入 val
// 如果小于，就什么都不做
public:
    KthLargest(int k, vector<int> &nums)
    {
        int n = nums.size();
        K = k;
        if (n < k)
        {   // 当 nums 的元素个数小于 k 时
            // nums 的所有元素均入队列
            for (int i = 0; i < n; i++)
                minpq.push(nums[i]);
        } else {
            // 当 nums 的元素个数大于 k 时
            // 将最大的 k 个元素加入队列
            for(int i = 0; i < k; i++)
                minpq.push(nums[i]);
            
            for(int i = k; i < n; i++) {
                // 删除小元素，加入大元素
                if(minpq.top() < nums[i]) {
                    minpq.pop();
                    minpq.push(nums[i]);
                }
            }
        }
    }

    int add(int val)
    {
        if(minpq.size() == K - 1) {
            minpq.push(val);
        } else {
            if(minpq.top() < val) {
                minpq.pop();
                minpq.push(val);
            }
        }

        return minpq.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> minpq;
    int K;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
