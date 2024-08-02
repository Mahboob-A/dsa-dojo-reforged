// 090524, Thursday, 05.30 pm 

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define f first
#define s second
#define vec vector<int>
#define vecPii vector<pair<int, int>>
#define pb push_back
#define ppb pop_back
#define DOUBLE_INF 1e18
#define INT_INF 1e9
const int N = 1e5 + 100;
vector<int> ans;
vector<pii> allSrc;
pii src, destination;
// priority_queue<pii, vecPii, greater<pii>>q;
vecPii adjList[N];
int visited[N];
int parent[N];
long long dist[N];
int n, m;

class Node
{
public:
        int val;
        Node *next;

        Node(int val)
        {
                this->val = val;
                this->next = NULL;
        }
};

// declaration
void insertAtTail(Node *&head, int val);
void initializeList(Node *&head);
void printList(Node *tmp);
Node *reverseListNonRecursive(Node *head);

// definition
void insertAtTail(Node *&head, int val)
{
        Node *tmp = head;
        Node *newNode = new Node(val);

        if (head == NULL)
        {
                head = newNode;
                return;
        }

        while (tmp->next != NULL)
        {
                tmp = tmp->next;
        }
        tmp->next = newNode;
}

void initializeList(Node *&head)
{
        int x = 5;
        for (int i = x; i >= 1; i--)
        {
                insertAtTail(head, i);
        }
        cout << "List initialization completed!" << endl;
}

void printList(Node *tmp)
{
        while (tmp != NULL)
        {
                cout << tmp->val;
                if (tmp->next != NULL)
                {
                        cout << " -> ";
                }
                tmp = tmp->next;
        }
}

Node *reverseListRecursive(Node *&head)
{
        // Base: if head is null or head -> next, return head.
        // at this position, we have reached to our new head.
        if (head == NULL || head->next == NULL)
                return head;

        // Recursive case: call with head -> next so that we reach to our new head.
        Node *newHead = reverseListRecursive(head->next);

        /*
                5 -> 3 -> 2 -> NULL
                at this position, for the first time, 2 will be returned, and 3 will be head at this time.
                this time, 3 -> next has 2, and 2 -> next has NULL.
                so, we have to update the 2-> next and put the 3's address there.
                3 is at this time, after the recursive call, (call stack: 0th index is 2, 1th index is 3 and 2th indexis 5)
                3 is head. so, head -> next is 2, and head -> next -> next is the 2 -> next.
                so, put 3 -> next -> next = 3 which is eventually head -> next -> next = head (as 3 is head after the recursive call returned)
                as we have updated the head's new position, now we need to put null to the head -> next
                so that 3 -> next does not store the 2's address anymore.
                so, head -> next = NULL will eventually delete the 2's address from the 3 -> next path,
                but we are successfully linked the 2 -> next = 3, but 3 -> next currently NULL
                which is pointing the end of the list.

                and then return the newHead, as from this node, the reverse relations are put together.

                And in this way, after each call returne, all the values till the original head will come one
                by one, and the head will put its address to its rightmost node's next, and put NULL in its next.
                Eventually, the original head -> next will have NULL and original head -> next -> next will point
                to the head.
        */

        head->next->next = head;
        head->next = NULL;

        
        // Node *frontNode = head -> next;
        // frontNode -> next = head; 
        // head -> next = NULL; 
        

       return newHead; 
}

int main()
{
        Node *head = NULL;

        // initialize the list
        initializeList(head);

        // print list
        cout << "List before reverse: \n";
        printList(head);

        head = reverseListRecursive(head);

        cout << "\nList after reverse Recursively: \n";
        printList(head);

        return 0;
}
