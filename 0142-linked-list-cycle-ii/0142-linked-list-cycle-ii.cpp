/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* tail = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                tail = head;
                break;
            }
        }
        
        if (tail == nullptr) return nullptr;
        while (tail != slow) {
            tail = tail->next;
            slow = slow->next;
        }

        return tail;
    }
};