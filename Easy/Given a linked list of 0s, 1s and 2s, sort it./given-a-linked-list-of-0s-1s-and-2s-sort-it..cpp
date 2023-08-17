//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
Node* segregate(Node *head) {
        
        // Add code here
        vector<int>v;
        struct Node *ptr=head;
        int o=0,a=0,b=0;
        while(ptr!=NULL){
            if(ptr->data==0){
                o++;
            }
            if(ptr->data==1){
                a++;
            }
            if(ptr->data==2){
                b++;
            }
            ptr=ptr->next;
        }
        // cout<<o<<a<<b<<endl;
        
        ptr=head;
        for(int i=0;i<o;i++){
            head->data=0;
            head=head->next;
        }
        for(int i=0;i<a;i++){
            head->data=1;
            head=head->next;
        }
        for(int i=0;i<b;i++){
            head->data=2;
            head=head->next;
        }
        return ptr;
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends