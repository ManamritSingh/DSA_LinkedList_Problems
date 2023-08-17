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
        ListNode* p = head;
        ListNode* q = head;
        ListNode* prev = nullptr;

        // Move p n steps ahead
        for (int i = 0; i < n; i++) {
            if (p) {
                p = p->next;
            } else {
                // Handle the case where n is greater than the list length
                return head;
            }
        }

        // Move p and q together until p reaches the end
        while (p) {
            p = p->next;
            prev = q;
            q = q->next;
        }

        // Handle removing the first node
        if (!prev) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Remove the Nth node from the end
        prev->next = q->next;
        delete q;

        return head;
    }
};
