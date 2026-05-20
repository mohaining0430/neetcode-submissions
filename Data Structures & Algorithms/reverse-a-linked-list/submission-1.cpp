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
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = new ListNode(0);
        while (head != nullptr) {
            ListNode *tmp = head->next;
            head->next = newHead->next;
            newHead->next = head;
            head = tmp;
        }
        return newHead->next;
    }
};
