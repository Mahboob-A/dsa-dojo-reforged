
// 130824, Tuesday, 10.00 am

#include <bits/stdc++.h>
#include "stack-template.h"
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

void insertAtBottom(Stack<int> &st, int insertVal)
{
        // If stack is empty, push the insertval from the other stack call
        if (st.empty())
        {
                st.push(insertVal);
                return;
        }

        // Stack is not empty: Empty the stack and push from reverse
        int topVal = st.Top();
        st.pop();

        insertAtBottom(st, insertVal);

        // Now, as the Stack was made empty, and the stack calls are being returned, push the current topVal in the current stack call
        st.push(topVal);
}

void reverseStack(Stack<int> &st)
{
        if (st.empty())
                return;

        // Empty the Stack
        int topVal = st.Top();
        st.pop();
        reverseStack(st);

        // Helper function to insert the value in the stack.
        insertAtBottom(st, topVal);
}

void sol()
{

        Stack<int> st;

        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);
        st.push(5);

        reverseStack(st);

        cout << "\nOriginal Stack: 5 4 3 2 1 " << endl;

        cout << "\nAfter Stack Reverse: " << endl;

        while (!st.empty())
        {
                cout << st.pop() << " ";
        }
        cout << endl
             << endl;
}

int main()
{

        sol();

        return 0;
}