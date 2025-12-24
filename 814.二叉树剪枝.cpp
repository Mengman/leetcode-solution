/*
 * @lc app=leetcode.cn id=814 lang=cpp
 *
 * [814] 二叉树剪枝
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
    TreeNode* pruneTree(TreeNode* root) {
        // 方法1：递归法
        if(root == nullptr) return root;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        if(root->left == nullptr && root->right == nullptr && root->val == 0) {
            return nullptr;
        } else {
            return root;
        }
    }
};
// @lc code=end

