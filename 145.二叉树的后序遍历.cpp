/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        // 方法1：递归版本
        // postorderRecurrent(root, ans);

        // 方法2: stack
        // postorderStack(root, ans);

        // 方法3：preorderTraversalReverse 反转先序遍历的结果（调整先序遍历的左右顺序）
        preorderTraversalReverse(root, ans);

        return ans;
    }

private:
    void postorderRecurrent(TreeNode* node, vector<int>& ans) {
        if (node == NULL) return;

        if (node->left != NULL) {
            postorderRecurrent(node->left, ans);
        }

        if (node->right != NULL) {
            postorderRecurrent(node->right, ans);
        }

        ans.push_back(node->val);
    }

    void postorderStack(TreeNode* node, vector<int>& ans) {
        // 1. 一直向左深度遍历，将所有左子节点入栈
        // 2. 右子树不存在或者右子树访问过，
        //        访问出栈节点， 并且出栈，标记当前节点为上一个访问过的节点
        //    否则，右子节点入栈
        // 3. 循环跳回步骤 1， 直到栈空
        
        if (node == nullptr) return;
        
        stack<TreeNode*> st;
        TreeNode* cur = node;
        TreeNode* prev = nullptr;
        
        while (cur != nullptr || !st.empty())
        {
            // 1. 一直向左深入，并将路径上的节点入栈
            while(cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            }

            // 2. 栈顶节点即为当前需要处理的节点
            cur = st.top();
            
            // 3. 检查右子树
            // 只有当右子树不存在， (叶子节点或者无右子树的父节点)
            // 或者右子树已经被访问过 (即等于 prev) 时， （父节点）
            // 才能访问根节点并出栈。
            if (cur->right == nullptr || cur->right == prev) {
                ans.push_back(cur->val);
                st.pop();
                prev = cur;
                cur = nullptr;
            } else {
                cur = cur->right;
            }
        }
        
    }

    void preorderTraversalReverse(TreeNode* node, vector<int>& ans) {
        if (node == nullptr) return;

        stack<TreeNode*> st;
        st.push(node);
        TreeNode* p = nullptr;
        
        while (!st.empty())
        {
            p = st.top(); st.pop();
            if (p == nullptr) continue;

            ans.push_back(p->val);
            st.push(p->left);
            st.push(p->right);
        }
        
        // NRL -> LRN
        reverse(ans.begin(), ans.end());
    }
};
// @lc code=end

