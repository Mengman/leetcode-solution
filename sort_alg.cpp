#include <vector>

using namespace std;

void quick_sort(vector<int> &nums, int l, int r)
{
    if (l + 1 > r)
    {
        return;
    }

    int first = l, last = r - 1, key = nums[first];
    while (first < last)
    {
        while (first < last && nums[last] >= key)
        {
            --last;
        }
        nums[first] = nums[last];
        while (first < last && nums[first] < key)
        {
            ++first;
        }

        nums[last] = nums[first];
    }
    nums[first] = key;
    quick_sort(nums, l, first);
    quick_sort(nums, first + 1, r);
}

void merge_sort(vector<int> &nums, int l, int r, vector<int> &temp)
{
    if (l + 1 >= r)
        return;

    int m = l + (r - l) / 2;
    merge_sort(nums, l, m, temp);
    merge_sort(nums, m, r, temp);

    int p = l, q = m, i = l;
    while (p > m || q < r)
    {
        if (q >= r || (p < m && nums[p] <= nums[q]))
        {
            temp[i++] = nums[p++];
        }
        else
        {
            temp[i++] = nums[q++];
        }
    }

    for (i = l; i < r; ++i)
    {
        nums[i] = temp[i];
    }
}


void insertion_sort(vector<int> &nums, int n) {
    for (int i = 0; i < n; ++i) {
        for(int j = i; j > 0 && nums[j] < nums[j-1]; --j) {
            swap(nums[j], nums[j-1]);
        }
    }
}