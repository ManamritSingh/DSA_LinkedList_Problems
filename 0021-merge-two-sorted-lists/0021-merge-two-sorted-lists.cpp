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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p = list1;
        ListNode* q = list2;

        if(p==NULL){
            return q;
        }
        if(q==NULL){
            return p;
        }

        ListNode* r = list1;

        if(p->val > q->val){
            r =q;
            q=q->next;
        }
        else{
            r=p;
            p=p->next;
        }
        ListNode* s = r;

        while(p && q){
            if(p->val < q->val){
                s->next=p;
                p=p->next;
            }
            else{
                s->next=q;
                q=q->next;
            }
            s=s->next;
        }
        if(!p){
            s->next=q;
        }
        else{
            s->next=p;
        }
        return r;

    }
};