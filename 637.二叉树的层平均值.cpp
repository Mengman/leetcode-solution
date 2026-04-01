/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> qu;
        qu.push(root);

        while (!qu.empty())
        {
            int n = qu.size();
            double total = 0;

            TreeNode* p;
            for(int i = 0; i < n; ++i) {
                p = qu.front();
                qu.pop();
                total += p->val;

                if(p->left) qu.push(p->left);

                if(p->right) qu.push(p->right);
            }
            res.push_back(total / n);
        }
        
        return res;
    }
};
// @lc code=end

