/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* lnode = dummy, *rnode = dummy;

        for(int i = 0; i <= right; ++i) {
            if (i < left-1) lnode = lnode->next;

            rnode = rnode->next;
        }

        ListNode* cur=lnode->next, *tmp, *rear = cur;
        for(int j=0; j < right-left+1; j++) {
            tmp = cur->next;
            cur->next = lnode->next;
            lnode->next = cur;
            cur = tmp;
        }

        rear->next = rnode;

        return dummy->next;
    }
};
// @lc code=end

