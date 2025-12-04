/*
 * @lc app=leetcode.cn id=965 lang=cpp
 *
 * [965] 单值二叉树
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
    bool isUnivalTree(TreeNode* root) {
        // 方法1: 前序遍历
        // return preorderTraversalCheck(root);

        // 方法2: 中序遍历
        // return inorderTraversalCheck(root);

        // 方法3: 后续遍历
        return postorderTraversalCheck(root);
    }

private:
    bool preorderTraversalCheck(TreeNode* root) {
        if (root == nullptr) return true;
        int val = root->val;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode* p = st.top(); st.pop();
            if(p->val != val) return false;

            if (p->right != nullptr) st.push(p->right);
            if (p->left != nullptr) st.push(p->left);
        }

        return true;
    }


    bool inorderTraversalCheck(TreeNode* root) {
        if(root == nullptr) return true;
        int val = root->val;
        TreeNode* p = root;

        stack<TreeNode*> st;
        while (!st.empty() || p != nullptr)
        {
            while (p != nullptr)
            {
                st.push(p);
                p = p->left;
            }

            if (!st.empty())
            {
                p = st.top(); st.pop();
                if (val != p->val) return false;
                p = p->right;
            }
        }

        return true;
    }


    bool postorderTraversalCheck(TreeNode* root) {
        if (root == nullptr) return true;
        int val = root->val;

        TreeNode* current = root;
        TreeNode* prev = nullptr;
        stack<TreeNode*> st;
        while (!st.empty() || current != nullptr)
        {
            while (current != nullptr)
            {
                st.push(current);
                current = current->left;
            }

            current = st.top();
            if(current->right == nullptr || current->right == prev) {
                if (current->val != val) return false;
                st.pop();
                prev = current;
                current = nullptr;
            } else {
                current = current->right;
            }
        }

        return true;
        
    }
};
// @lc code=end

