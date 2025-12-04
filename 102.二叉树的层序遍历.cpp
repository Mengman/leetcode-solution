/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        preorder(root, 0, ans);
        return ans;
    }

private:
    void preorder(TreeNode* node, int level, vector<vector<int>>& ans) {
        if(node == nullptr) return;

        if(level < ans.size()) {
            ans[level].push_back(node->val);
        } else {
            ans.push_back({node->val});
        }

        preorder(node->left, level + 1, ans);
        preorder(node->right, level + 1, ans);
    }
};
// @lc code=end

