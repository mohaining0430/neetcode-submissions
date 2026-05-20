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

/*
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *newHead = new ListNode(0);
        newHead->next = head;

        ListNode *left = newHead, *right = head;
        while (n-- > 0)
            right = right->next;

        while (right != nullptr) {
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next;

        return newHead->next;
    }
};
*/