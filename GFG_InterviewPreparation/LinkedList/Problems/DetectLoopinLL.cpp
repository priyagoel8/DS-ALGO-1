// Detect Loop in linked list 
// Given a linked list of N nodes. The task is to check if the the linked list has a loop. Linked list can contain self loop.

// Example 1:

// Input:
// N = 3
// value[] = {1,3,4}
// x = 2
// Output: True
// Explanation: In above test case N = 3.
// The linked list with nodes N = 3 is
// given. Then value of x=2 is given which
// means last node is connected with xth
// node of linked list. Therefore, there
// exists a loop.
// Example 2:

// Input:
// N = 4
// value[] = {1,8,3,4}
// x = 0
// Output: False
// Explanation: For N = 4 ,x = 0 means
// then lastNode->next = NULL, then
// the Linked list does not contains
// any loop.
// Your Task:
// The task is to complete the function detectloop() which contains reference to the head as only argument. This function should return 1 if linked list contains loop, else return 0.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 104
// 1 <= Data on Node <= 103

// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool detectLoop(Node* head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        if( detectLoop(head) )
            cout<< "True\n";
        else
            cout<< "False\n";
    }
	return 0;
}
// } Driver Code Ends


/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/

bool detectLoop(Node* head)
{
    // your code here
    Node *slowptr=head;
    Node *fastptr=head;
    while(slowptr && fastptr && fastptr->next)
    {
        slowptr=slowptr->next;
        fastptr=fastptr->next->next;
        if(slowptr==fastptr)
            return 1;
    }
    return 0;
}




