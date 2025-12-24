/*
 * @lc app=leetcode.cn id=2487 lang=cpp
 *
 * [2487] 从链表中移除节点
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
    ListNode* removeNodes(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // 方法1：暴力计算(超时)
        // ListNode* cur = head;
        // ListNode* prev = nullptr;
        // ListNode* newHead = head;

        // while(cur->next != nullptr) {
        //     if(cur->val < findMaxValue(cur->next)) {
        //         if (prev == nullptr) {
        //             cur = cur->next;
        //             newHead = cur;
        //         } else {
        //             prev->next = cur->next;
        //             cur = cur->next;
        //         }
            
        //     } else {
        //         prev = cur;
        //         cur = cur->next;
        //     }
        // }
        // return newHead;


        // 方法2： reverse twice
        // ListNode* newHead = reverse(head);
        
        // ListNode* cur = newHead->next;
        // ListNode* prev = newHead;

        // while (cur != nullptr)
        // {
        //     if(cur->val < prev->val) {
        //         prev->next = cur->next;
        //         cur = cur->next;
        //     } else {
        //         prev = cur;
        //         cur = cur->next;
        //     }
        // }
        
        // // reverse again
        // ListNode* ans = reverse(newHead);

        // return ans;

        // 方法3：递归
        ListNode* ans = recursionRemoveNodes(head);
        return ans;

    }

    ListNode* recursionRemoveNodes(ListNode* head) {
        if (head->next == nullptr) return head;

        ListNode* p = recursionRemoveNodes(head->next);

        if (head->val < p->val) {
            return p;
        } else {
            head->next = p;
            return head;
        }
    }

    ListNode* reverse(ListNode* head) {
        ListNode* tail = head;
        ListNode* p = head, *tmp;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }

        while (p != tail)
        {
            tmp = p->next;
            p->next = tail->next;
            tail->next = p;
            p = tmp;
        }

        return tail;
    }

    int findMaxValue(ListNode* p) {
        int v = p->val;
        while (p != nullptr)
        {
            if (v < p->val) {
                v = p->val;
            }
            p = p->next;
        }
        return v;
    }
};
// @lc code=end

