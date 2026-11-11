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
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
    ListNode* mergeSort(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        // use slow and fast pointers approach to find the mid
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // split the list into two halves
        ListNode* temp = slow;
        prev->next = nullptr;

        // divide
        head = mergeSort(head);
        temp = mergeSort(temp);

        //conquer
        return merge(head, temp);

    }
    
    // sort and merge the two halves
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // sort and store to the dummy LL
        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                tail->next = left;
                tail = tail->next;
                left = left->next;
            }
            else {
                tail->next = right;
                tail = tail->next;
                right = right->next;
            }
        }
        
        // store the remaining nodes of left to the dummy LL
        while (left != nullptr) {
            tail->next = left;
            tail = tail->next;
            left = left->next;
        }
        // store the remaining nodes of right to the dummy LL
        while (right != nullptr) {
            tail->next = right;
            tail = tail->next;
            right = right->next;
        }

        // return the head of the merged list
        ListNode* result = dummy.next;
        return result;
    }
};