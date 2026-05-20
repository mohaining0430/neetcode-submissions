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
        // [0 1 2 3 4 5 6] case, slow will be 3, first list [0 1 2 3], second list [4 5 6]
        // [0 1 2 3 4 5] case, slow will be 2, first list [0 1 2], second list [3 4 5]
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
        // Even number of nodes: first list and second list has same number of nodes.
        // Odd number of nodes: first list has one more node.
        // So checking second != nullptr is sufficient
        while (second != nullptr) {
            ListNode *tmp1 = cur->next;
            ListNode *tmp2 = second->next;
            cur->next = second;
            second->next = tmp1;
            cur = tmp1;
            second = tmp2;
        }

        // Don't forget this - for odd number case. setting 3->next = null in the example.
        if (cur != nullptr)
            cur->next = nullptr;
    }
};
