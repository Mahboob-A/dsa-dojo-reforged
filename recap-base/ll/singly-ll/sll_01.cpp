// singly linked list recap
// 300424, Tuesday, 08.00 pm

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
        int value;
        Node *next;

        Node(int val)
        {
                value = val;
                next = NULL;
        }
};

void insertAtTail(Node *&head, int val)
{
        Node *newNode = new Node(val);
        if (head == NULL)
        {
                head = newNode;
                return;
        }

        Node *tmp = head;
        while (tmp->next != NULL)
        {
                tmp = tmp->next;
        }
        tmp->next = newNode;
}

void insertAtHead(Node *&head, int val)
{
        Node *newNode = new Node(val);

        newNode->next = head;
        head = newNode;
}

void displayList(Node *tmp)
{
        cout << "display list: \n";
        while (tmp != NULL)
        {
                cout << tmp->value;
                if (tmp->next != NULL)
                {
                        cout << " -> ";
                }
                tmp = tmp->next;
        }
        cout << "\n";
}

int main()
{
        Node *head = NULL;

        int n, choice;
        cout << "insertAtHead: 1 | insertAtTail: 2 => ";
        cin >> choice;

        while (choice == 1 || choice == 2)
        {
                cout << "Input value: ";
                cin >> n;

                if (choice == 1)
                        insertAtHead(head, n);
                else if (choice == 2)
                        insertAtTail(head, n);

                cout << "insertAtHead: 1 | insertAtTail: 2 => ";
                cin >> choice;
                cout << "\n";
        }

        displayList(head);

        return 0;
}
