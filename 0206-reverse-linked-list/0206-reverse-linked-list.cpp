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
        ListNode* curr = head;   // Initialize 'curr' with the 'head' of the linked list
        ListNode* forw = nullptr; // Initialize 'forw' as 'nullptr'
        ListNode* prev = nullptr; // Initialize 'prev' as 'nullptr'

        while (curr != nullptr) {
            forw = curr->next;   // Store the next node in 'forw'
            curr->next = prev;   // Reverse the current node's 'next' pointer
            prev = curr;         // Move 'prev' to the current node
            curr = forw;         // Move 'curr' to the next node
        }

        return prev; // The new 'head' of the reversed linked list is 'prev'
    }
};
