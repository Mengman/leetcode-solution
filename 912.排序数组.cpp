/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start

template<typename T>
bool cmp(T a, T b) {
    return a > b;
}

template<typename T>
class Heap{
    int n;
    vector<T> R;

    void shiftDown(int low, int high) {
        int i = low;
        int j = 2*i + 1;
        T tmp = R[i];
        while (j <= high)
        {
            if (j < high && cmp(R[j], R[j+1])) j++;

            if (cmp(tmp, R[j])) {
                R[i] = R[j];
                i = j;
                j = 2*i + 1;
            } 
            else break;
        }
        R[i] = tmp;
    }

    void shiftUp(int j) {
        int i = (j-1)/2;
        T tmp = R[j];
        while (j!=0)
        {
            if(cmp(R[i], tmp)) {
                R[j] = R[i];
                j=i;
                i = (j-1)/2;
            } else break;
        }
        R[j] = tmp;
    }

public:
    Heap():n(0){}

    void push(T e) {
        R.push_back(e);
        n++;
        if(n==1) return;
        int j = n-1;
        shiftUp(j);
    }

    T pop() {
        T e = R[0];
        R[0] = R[n-1];
        R.pop_back();
        n--;
        if(n>1) shiftDown(0, n-1);
        return e;
    }

    T top() {
        return R[0];
    }

    bool empty() {
        return n == 0;
    }
};


class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // randomized_quicksort(nums, 0, (int)nums.size()-1);

        heapSort(nums);
        return nums;
    }

    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j <= r - 1; ++j) {
            if (nums[j] < pivot) {
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }

    int randomized_partition(vector<int>& nums, int l, int r) {
        int i = rand() % (r - l + 1) + l; // 随机选一个作为我们的主元
        swap(nums[r], nums[i]);
        return partition(nums, l, r);
    }

    void randomized_quicksort(vector<int>& nums, int l, int r) {
        if (l < r) {
            int pos = randomized_partition(nums, l, r);
            randomized_quicksort(nums, l, pos - 1);
            randomized_quicksort(nums, pos + 1, r);
        }
    }

    void heapSort(vector<int>& nums) {
        Heap<int> pq;
        for(int x : nums) pq.push(x);
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = pq.top();
            pq.pop();
        }
    }
};
// @lc code=end

