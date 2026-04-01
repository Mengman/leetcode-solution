/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> hmap;
        for (int i = 0; i < inorder.size(); ++i)
        {
            hmap[inorder[i]] = i;
        }

        return buildTreePreorderInorder(
            preorder,
            0,
            preorder.size() - 1,
            inorder,
            0,
            inorder.size() - 1,
            hmap);
    }

    TreeNode *buildTreePreorderInorder(
        vector<int> &preorder,
        int pStart,
        int pEnd,
        vector<int> &inorder,
        int iStart,
        int iEnd,
        unordered_map<int, int> &hmap)
    {
        if (pStart > pEnd || iStart > iEnd)
        {
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[pStart]);

        int inorderIdx = hmap[preorder[pStart]];
        int leftNum = inorderIdx - iStart;
        int rightNum = iEnd - inorderIdx;

        root->left = buildTreePreorderInorder(
            preorder,
            pStart + 1,
            pStart + leftNum,
            inorder,
            iStart,
            inorderIdx - 1,
            hmap);

        root->right = buildTreePreorderInorder(
            preorder,
            pStart + leftNum + 1,
            pEnd,
            inorder,
            inorderIdx + 1,
            iEnd,
            hmap);

        return root;
    }
};
// @lc code=end
