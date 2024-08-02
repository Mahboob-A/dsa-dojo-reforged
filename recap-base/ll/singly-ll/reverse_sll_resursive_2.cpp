
// Reverse SLL Recursive. 020824

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

void printList(Node *head);
void insertAtTail(Node *&head, int val);
void initializeList(Node *&head);
Node *reverseListRecursive(Node *&head);

void insertAtTail(Node *&head, int val)
{
        Node *newNode = new Node(val);
        Node *tmp = head;

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

Node *reverseListRecursive(Node *&head)
{
        if (head == NULL || head->next == NULL)
                return head;

        Node *newHead = reverseListRecursive(head->next);

        head->next->next = head;
        head->next = NULL;

        return newHead;
}

void initializeList(Node *&head)
{
        int n = 5;
        for (int i = 1; i <= n; i++)
                insertAtTail(head, i);
}

void printList(Node *head)
{
        while (head != NULL)
        {
                cout << head->val;
                if (head->next != NULL)
                        cout << " -> ";
                head = head->next;
        }
}

void sol()
{

        Node *head = NULL;

        initializeList(head);

        cout << "\nList Before Reverse: " << endl;
        printList(head);

        head = reverseListRecursive(head);

        cout << "\nList After Reverse: " << endl;
        printList(head);
        cout << endl;
}

int main()
{

        sol();

        return 0;
}