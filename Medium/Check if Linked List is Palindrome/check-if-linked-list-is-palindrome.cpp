//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
#include<vector>
class Solution{
  public:
    //Function to check whether the list is palindrome.
    
    Node* getMiddle(Node* head){
        Node* fast = head -> next;
        Node* slow = head;
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }
    
    Node* reverse(Node * head){
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
    
    bool isPalindrome(Node *head)
    {
        
        // Approach 2
        Node* mid = getMiddle(head);
        Node* temp = mid -> next;
        
        mid -> next = reverse(temp);
        
        Node* head1 = head;
        Node* head2 = mid -> next;
        while(head2 != NULL){
            if(head1 -> data != head2 -> data){
                return false;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        
        mid -> next = reverse(temp);
        return true;
        
        /*
        // Approach 1
        Node* temp = head;
        vector<int> arr;
        while(temp != NULL){
            arr.push_back(temp -> data);
            temp = temp -> next;
        }
        
        int s = 0;
        int e = arr.size() - 1;
        
        while(s < e){
            if(arr[s++] != arr[e--])
                return false;
                
        }
        return true;
        */
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends