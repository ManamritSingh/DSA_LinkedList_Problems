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
    bool hasCycle(ListNode *head) {
        ListNode * p = head , *q = p;

        if( p==NULL || p->next == NULL){
            return false;
        }

        do{
            p=p->next;
            if(p){
                p=p->next;
            }
            q=q->next;
        }while( p && q && p!= q);

        if(p==q){
            return true;
        }
        else{
            return false;
        }
    }
};