/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        preorder(root, 0, ans);
        return ans;
    }

private:
    void preorder(TreeNode* node, int h, vector<int>& ans) {
        if (node == nullptr) return;
        if (h < ans.size()) {
            ans[h] = node->val;
        } else {
            ans.push_back(node->val);
        }
        
        preorder(node->left, h+1, ans);
        preorder(node->right, h+1, ans);
    }
};
// @lc code=end

