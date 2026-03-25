/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
    int widthOfBinaryTree(TreeNode* root) {
        return levelOrder(root);
    }

    int levelOrder(TreeNode* root) {
        // 分层的层次遍历
        queue<pair<TreeNode*, unsigned long long>> qu;
        qu.push({root, 1L});

        int ans = 0;
        while (!qu.empty())
        {
            int n = qu.size();
            vector<unsigned long long> tmp;
            for(int i = 0; i <n; ++i) {
                auto [p, idx] = qu.front();
                qu.pop();

                tmp.push_back(idx);

                if (p->left) {
                    qu.push({p->left, idx * 2});
                }

                if (p->right) {
                    qu.push({p->right, idx * 2 + 1});
                }
            }

            if (tmp.size() == 1) {
                ans = max(ans, 1);
            } else {
                ans = max(ans, (int)(tmp.back() - tmp[0] + 1));
            }
        }

        return ans;
    }
};
// @lc code=end

