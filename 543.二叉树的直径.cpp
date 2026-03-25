/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        bfs(root, ans);
        return ans;
    }

    int bfs(TreeNode* root, int& ans) {
        // 广度遍历
        // 对于每个结点，直径 = 左子树长度 + 右子树长度

        // 叶子结点
        if (root->left == nullptr && root->right == nullptr) {
            ans = max(ans, 0);
            return 1;
        }

        int leftLen = 0, rightLen = 0;
        if (root->left) {
            leftLen = bfs(root->left, ans);
        }

        if (root->right) {
            rightLen = bfs(root->right, ans);
        }

        ans = max(ans, leftLen + rightLen);

        return max(leftLen, rightLen) + 1;
    }
};
// @lc code=end

