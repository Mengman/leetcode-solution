/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        // 解法1：遍历移动
        // if (head == NULL || head->next == NULL) {
        //     return head;
        // }

        // // 计算节点个数
        // int node_num = 1;
        // ListNode* r = head;
        // while(r->next != NULL) {
        //     r = r->next;
        //     node_num += 1;
        // }

        // k = k % node_num;
        // if (k == 0) {
        //     return head;
        // }

        // ListNode* tmp = head;
        // for(int i =0; i < node_num - k - 1; i++) {
        //     tmp = tmp->next;
        // }

        // ListNode* new_head = tmp->next;
        // r->next = head;
        // tmp->next = NULL;
        // return new_head;

        // 解法2：使用循环链表
        if (k == 0 || head == NULL || head->next == NULL) {
            return head;
        }

        // 计算节点个数
        int node_num = 1;
        ListNode* p = head;
        while(p->next != NULL) {
            p = p->next;
            node_num++;
        }

        // 首位链接形成循环链表
        p->next = head;

        // 寻找断开的节点
        k = k % node_num;
        int m = node_num - k;
        while (m > 0)
        {
            head = head->next;
            p = p->next;
            m--;
        }
        // 断开循环
        p->next = NULL;
        return head;
    }
};
// @lc code=end

