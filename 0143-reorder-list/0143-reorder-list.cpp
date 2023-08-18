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
    void reorderList( ListNode* head) {
        if((!head) || (!head->next) || (!head->next->next))
            return;

        stack<ListNode*> my_stack;
        ListNode* p = head;

        int size=0;

        while(p){
            my_stack.push(p);
            size++;
            p=p->next;
        }

        ListNode* q = head;

        for(int j =0 ; j<size/2 ; j++){
            ListNode *e = my_stack.top();
            my_stack.pop();
            e->next = q->next;
            q->next=e;

            q=q->next->next;
        }
        q->next= NULL;
    }
        
};