/*
 * @lc app=leetcode.cn id=881 lang=cpp
 *
 * [881] 救生艇
 */

// @lc code=start
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());

        int ans = 0;
        int i = 0, j = n - 1;
        while (i <= j)
        {
            if (i == j) {
                ans++;
                break;
            }
            if(people[i] + people[j] <= limit) {
                ans++;
                i++;
                j--;
            } else {
                ans++; 
                j--;
            }
        }
        return ans;
    }
};
// @lc code=end

