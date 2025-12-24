/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 方法1： 递归法
        if(root == nullptr || root == p || root == q) return root;

        TreeNode* leftChildren = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightChildren = lowestCommonAncestor(root->right, p, q);

        if (leftChildren != nullptr && rightChildren != nullptr) {
            return root;
        } else if (leftChildren == nullptr && rightChildren != nullptr) {
            return rightChildren;
        } else if (leftChildren != nullptr && rightChildren == nullptr) {
            return leftChildren;
        } else {
            return nullptr;
        }
    }
};
// @lc code=end

