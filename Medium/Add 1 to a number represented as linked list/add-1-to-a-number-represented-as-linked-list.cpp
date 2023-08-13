//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* forw = NULL;
        
        while(curr != NULL){
            forw = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
    void createNode(Node* &head, Node* &tail, int data){
        Node* temp = new Node(data);
        if(head == NULL){
            head = temp;
            tail = temp;
        }
        else{
            tail -> next = temp;
            tail = temp;
        }
    }
    public:
    Node* addOne(Node *head) 
    {
        if(head -> next != NULL)
            head = reverse(head);
            
        int carry = 1;
        int sum = 0;
        int digit = 0;
        
        Node* temp = head;
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while(temp != NULL || carry != 0){
            if(temp != NULL){
                sum = carry + temp -> data;
                digit = sum % 10;
                createNode(ansHead, ansTail, digit);
                carry = sum / 10;
                temp = temp -> next;
            }
            else{
                sum = carry;
                digit = sum % 10;
                createNode(ansHead, ansTail, digit);
                carry = sum / 10;
            }
        }
        ansHead = reverse(ansHead);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends