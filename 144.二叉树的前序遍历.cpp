/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        // 方法1：递归版本
        // preorderRecurrence(root, ans);

        // 方法2：非递归 Stack
        // preorderStack(root, ans);

        // 方法3
        leftDeepTraversal(root, ans);
        return ans;
    }

private:
    void preorderRecurrence(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) {
            return;
        } else {
            ans.push_back(root->val);
            preorderRecurrence(root->left, ans);
            preorderRecurrence(root->right, ans);
        }
    }

    void preorderStack(TreeNode* root, vector<int>& ans) {
        // 1. 访问当前节点
        // 2. 当前节点右子节点入栈
        // 3. 当前节点左子节点入栈
        // 4. 循环跳回步骤 1， 直到栈空
        if (root == nullptr) return;
        
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode* node = st.top(); st.pop();
            if (node == nullptr) continue;

            ans.push_back(node->val);
            st.push(node->right);
            st.push(node->left);
        }
    }


    void leftDeepTraversal(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;
        stack<TreeNode*> st;
        TreeNode* p = root;
        while (!st.empty() || p != nullptr)
        {
            while (p != nullptr)
            {
                // 一直向左查找子节点
                ans.push_back(p->val);
                st.push(p);
                p = p->left;
            }

            if (!st.empty())
            {
                // 没有左子节点，去到右子节点
                p = st.top(); st.pop();
                p = p->right;
            }
        }
    }
};
// @lc code=end

