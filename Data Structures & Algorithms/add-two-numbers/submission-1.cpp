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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *newhead = new ListNode(0), *cur = newhead;
        int sum = 0;
        while (l1 != nullptr && l2 != nullptr) {
            cur->next = new ListNode ((l1->val + l2->val + sum) % 10);
            sum = (l1->val + l2->val + sum) / 10;
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != nullptr) {
            cur->next = new ListNode ((l1->val + sum) % 10);
            sum = (l1->val + sum) / 10;
            cur = cur->next;
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            cur->next = new ListNode ((l2->val + sum) % 10);
            sum = (l2->val + sum) / 10;
            cur = cur->next;
            l2 = l2->next;
        }     

        if (sum > 0) {
            cur->next = new ListNode(sum);
        }

        return newhead->next;   
    }
};
