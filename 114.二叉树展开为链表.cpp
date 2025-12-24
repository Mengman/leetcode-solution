/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        vector<TreeNode*> v;
        // 方法1：递归前序遍历
        // preorderRecurrence(root, v);

        // 方法2：非递归stack前序遍历
        preorderStack(root, v);

        // 方法3：向左深度遍历
        leftDeepTraversal(root, v);

        for(int i = 0; i < v.size() - 1; i++) {
            v[i]->right = v[i+1];
            v[i]->left = nullptr;
        }

        v[v.size() - 1]->right = nullptr;
        v[v.size() - 1]->left = nullptr;
    }

    void preorderRecurrence(TreeNode* root, vector<TreeNode*>& v) {
        if (root == nullptr) return;
        
        v.push_back(root);
        
        preorderRecurrence(root->left, v);
        preorderRecurrence(root->right, v);
    }

    void preorderStack(TreeNode* root, vector<TreeNode*>& v) {
        stack<TreeNode*> st;

        st.push(root);
        while (!st.empty())
        {
            TreeNode* node = st.top(); st.pop();
            if(node == nullptr) continue;
            v.push_back(node);

            st.push(node->right);
            st.push(node->left);
        }
    }

    void leftDeepTraversal(TreeNode* root, vector<TreeNode*>& v) {
        if(root == nullptr) return;
        stack<TreeNode*> st;
        TreeNode* p = root;
        while (!st.empty() && p != nullptr)
        {
            while (p != nullptr)
            {
                v.push_back(p);
                st.push(p);
                p = p->left;
            }

            while (!st.empty())
            {
                p = st.top(); st.pop();
                p = p->right;
            }
        }
        
    }
};
// @lc code=end

