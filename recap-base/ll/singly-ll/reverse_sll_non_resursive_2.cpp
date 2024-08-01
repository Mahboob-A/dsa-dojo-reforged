
// 010824, Thursday, 07.00 am

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
priority_queue<pii, vecPii, greater<pii>> q;
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

void initialize_list(Node *&head)
{
        int n = 5;
        for (int i = 1; i <= n; i++)
                insertAtTail(head, i);

        cout << "\nList Initialization Completed!";
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
        cout << endl;
}

Node *reverseListNonRecursive(Node *&head)
{
        Node *curr = head;
        Node *prev = NULL;
        Node *Next = NULL;

        while (curr != NULL)
        {
                Next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = Next;
        }
        return prev;
}

int main()
{
        cout << "\nSingly Linked List Reverse Non-Recursive\n";
        Node *head = NULL;

        // initialize the list
        initialize_list(head);

        cout << "\nList Before Reverse: ";
        printList(head);

        head = reverseListNonRecursive(head);

        cout << "\nList After Reverse: ";
        printList(head);

        return 0;
}
