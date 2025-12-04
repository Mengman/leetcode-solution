/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        // 方案1： 递归版本
        // inorderTraversalRecurrent(root, ans);

        // 方案2：非递归版本
        inorderTraversalStack(root, ans);
        return ans;
    }

private:
    void inorderTraversalRecurrent(TreeNode* node, vector<int>& ans) {
        if (node == nullptr) return;

        inorderTraversalRecurrent(node->left, ans);
        ans.push_back(node->val);
        inorderTraversalRecurrent(node->right, ans);
    }


    void inorderTraversalStack(TreeNode* node, vector<int>& ans) {
        // 1. 一直向左深度遍历，将所有左子节点入栈
        // 2. 出栈访问节点
        // 3. 将右子节点入栈
        // 4. 循环跳回步骤 1，直到栈空
        if (node == nullptr) return;

        stack<TreeNode*> st;
        TreeNode* p = node;

        while (!st.empty() || p != nullptr)
        {
            // 1. 一直向左，将所有左子节点入栈
            while (p != nullptr)
            {
                st.push(p);
                p = p->left;
            }

            if(!st.empty()) {
                p = st.top(); st.pop();
                ans.push_back(p->val);
                p = p->right;
            }
        }
    }
};
// @lc code=end

