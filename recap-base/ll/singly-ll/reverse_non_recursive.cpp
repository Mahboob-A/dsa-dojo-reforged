// 050524, Sunday, 05.00 pm 


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

/*
Reverse Linked List Non Recursive 
*/

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
        int n = 5;
        for (int i = n; i >= 1; i--)
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

Node *reverseListNonRecursive(Node *head)
{
        Node *prev = NULL;
        Node *Next = NULL;
        Node *curr = head;

        // curr and Next will point to the same node while prev node will point the previous node of curr and Next.
        // Next will become NULL first, then curr will be NULL.
        // prev pointer  will be at the last node in the list. return prev pointer and update it with head.
        while (curr != NULL)
        {
                // 1. get the next node in the list via the curr node
                Next = curr->next;

                // 2. put the prev node in the current node's next pointer.
                curr->next = prev;

                // 3. make the current node as the  previous node
                prev = curr;

                // 4. now move forward to the next node, which is already stored in the Next pointer.
                curr = Next;
        }
        return prev;
}

int main()
{
        Node *head = NULL;

        // initialize the list
        initializeList(head);

        // print list
        cout << "List before reverse: \n";
        printList(head);

        head = reverseListNonRecursive(head);

        cout << "\nList after reverse Non-Recursively: \n";
        printList(head);

        return 0;
}
