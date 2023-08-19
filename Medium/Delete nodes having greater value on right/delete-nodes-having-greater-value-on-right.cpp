//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        Node* prev=NULL;
        Node* curr = head;
        Node* nex = NULL;
        
        while(curr){
                nex=curr->next;
                curr->next=prev;
                prev=curr;
                curr=nex;
        }
        head=prev;
        
        int max = head->data;
        Node*p = head;
        Node*r =p;
        while(p){
            if(p->data >= max){
                max=p->data;
                r=p;
                p=p->next;
            }
            else if(p->data < max){
                Node*q=p;
                r->next=p->next;
                p=p->next;
                delete q;
            }
        }
        
        prev=NULL;
        curr = head;
        nex = NULL;
        
        while(curr){
                nex=curr->next;
                curr->next=prev;
                prev=curr;
                curr=nex;
        }
        head=prev;
        
        
        return head;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends