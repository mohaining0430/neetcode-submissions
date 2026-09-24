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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* node1, ListNode* node2) {return node1->val > node2->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;
        ListNode* newHead = new ListNode(0), *cur = newHead;
        for (auto list : lists)
            if(list != nullptr)
                pq.push(list);
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            cur->next = node;
            cur = cur->next;
            if (node->next != nullptr)
                pq.push(node->next);
        }
        return newHead->next;
    }
};