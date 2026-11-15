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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // reverse the second half of the list
        ListNode* newHead = reverseList(slow);
        ListNode* temp = newHead; // so the reversed list can be restored after operations
        
        slow = head;
        bool flag = true;
        while (temp != NULL) {
            if (slow->val != temp->val) {
                flag = false;
                break;
            }
            slow = slow->next;
            temp = temp->next;
        }

        // restore the original list
        reverseList(newHead);

        return flag;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
};