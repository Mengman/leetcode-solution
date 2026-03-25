/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 先遍历对比 p q
        return preorderCheck(p, q);
    }

    bool preorderCheck(TreeNode* p, TreeNode* q) {
        if (p != nullptr && q != nullptr) {
            if (p->val != q->val) return false;

            bool leftTreeCheck = preorderCheck(p->left, q->left);
            bool rightTreeCheck = preorderCheck(p->right, q->right);

            return leftTreeCheck && rightTreeCheck;
        } else if (p == nullptr && q == nullptr) {
            return true;
        } else {
            return false;
        }
    }

};
// @lc code=end

