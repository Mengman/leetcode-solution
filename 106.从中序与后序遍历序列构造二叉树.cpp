/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> hmap;
        for(int i = 0; i < inorder.size(); ++i) {
            hmap[inorder[i]] = i;
        }

        return buildTreeFromInorderPostorder(
            inorder,
            0,
            inorder.size()-1,
            postorder,
            0,
            postorder.size() - 1,
            hmap
        );
    }

    TreeNode* buildTreeFromInorderPostorder(
        vector<int>& inorder,
        int iStart,
        int iEnd,
        vector<int>& postorder,
        int pStart,
        int pEnd,
        unordered_map<int, int> hmap
    ) {
        if (iStart > iEnd || pStart > pEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[pEnd]);

        int inorderIdx = hmap[postorder[pEnd]];
        int leftNum = inorderIdx - iStart;
        int rightNum = iEnd - inorderIdx;

        root->left = buildTreeFromInorderPostorder(
            inorder,
            iStart,
            inorderIdx-1,
            postorder,
            pStart,
            pStart + leftNum - 1,
            hmap
        );

        root->right = buildTreeFromInorderPostorder(
            inorder,
            inorderIdx+1,
            iEnd,
            postorder,
            pEnd - rightNum,
            pEnd - 1,
            hmap
        );

        return root;
    }
};
// @lc code=end

