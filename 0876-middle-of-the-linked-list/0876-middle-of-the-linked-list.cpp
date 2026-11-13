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
    ListNode* middleNode(ListNode* head) {
        return findMiddle(head, head);
    }
    ListNode* findMiddle(ListNode* slow, ListNode* fast) {
        if (fast == nullptr || fast->next == nullptr) return slow;
        return findMiddle(slow->next, fast->next->next);
    }
};