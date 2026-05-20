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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *front = head, *back = head;
        while (n-- > 0)
            front = front->next;

        ListNode *prev = nullptr;
        while (front != nullptr) {
            front = front->next;
            prev = back;
            back = back->next;
        }

        if (back == head)
            return head->next;
            
        prev->next = back->next;

        return head;
    }
};
