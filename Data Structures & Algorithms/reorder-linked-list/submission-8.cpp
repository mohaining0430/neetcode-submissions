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
    // Can skip. Not very interesting.
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *second = slow->next;
        ListNode *newSecond = new ListNode(0);
        while (second != nullptr) {
            ListNode *tmp = second->next;
            second->next = newSecond->next;
            newSecond->next = second;
            second = tmp;
        }

        second = newSecond->next;
        ListNode *cur = head;
        while (second != nullptr) {
            ListNode *tmp1 = cur->next;
            ListNode *tmp2 = second->next;
            cur->next = second;
            second->next = tmp1;
            cur = tmp1;
            second = tmp2;
        }
        if (cur != nullptr)
            cur->next = nullptr;
    }
};
