/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return head;
        }

        ListNode* h1 = new ListNode(-1), *r1 = h1;
        ListNode* h2 = new ListNode(-1), *r2 = h2;
        ListNode* p = head;
        
        while(p != NULL) {
            // 第一次插入奇数节点
            r1->next = p;
            r1 = r1->next;
            p = p->next;

            // 第二次插入偶数节点
            if (p != NULL) {
                r2->next = p;
                r2 = r2->next;
                p = p->next;
            }
        }

        // 连接 h1 和 h2
        r1->next = h2->next;
        // 防止循环链接
        r2->next = NULL;
        return h1->next;
    }
};
// @lc code=end

