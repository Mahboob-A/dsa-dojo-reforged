// sll recap on 010524, Wednesday, 08.30 pm

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

void insertAtHead(Node *&head, int val);
void insertAtTail(Node *&head, int val);
void insertAtSpecificPos(Node *&head, int val, int pos);
int searchByValueUniqueList(Node *&head, int key);

void insertAfterAValueUniqueList(Node *&head, int key, int value);
void insertBeforeAValueUniqueList(Node *&head, int key, int value);
void deleteAtHead(Node *&head);
// Array searchDupeListReturn(Node *&head, int key);

int countNode(Node *&head);
void initializeList(Node *&head);
void printList(Node *head);

// insert value in the list at the Head of it.
void insertAtHead(Node *&head, int val)
{
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
}

// insert value in the list at the Tail of it.
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

// insert a value in the list at a specific position
void insertAtSpecificPos(Node *&head, int val, int pos)
{
        Node *tmp = head;
        Node *newNode = new Node(val);

        int total_nodes = countNode(head);

        //  total_nodes + 1 as we would allow to insert at the tail'th position also.
        if (pos > total_nodes + 1)
        {
                cout << "Error!\n";
                cout << "Total nodes: " << total_nodes << " And the position to insert is: " << pos << " which is an invalid position.\n";
                cout << "Possible positions are between: 1 to " << total_nodes + 1 << endl;
                return;
        }

        if (pos < 1)
        {
                cout << "ERROR!: Position can not be less than 1.\n";
                return;
        }

        if (tmp == NULL)
        {
                cout << "ERROR!: Invalid position. There are no previous node in the list. " << endl;
                return;
        }

        if (pos == 1)
        {
                // Node *prev_head = head;
                // head = newNode;
                // newNode->next = prev_head;

                insertAtHead(head, val);
                cout << "DONE!\n";
                return;
        }

        int i = 1;
        while (i < pos - 1)
        {
                tmp = tmp->next;
                i++;
        }

        newNode->next = tmp->next;
        tmp->next = newNode;
        cout << "DONE!\n";
}

// search the list if a value is present in it.
int searchByValueUniqueList(Node *&head, int key)
{
        // as list does not have index, convention is list starts at position which beings at 1.
        int position = 1;
        Node *tmp = head;

        if (tmp == NULL)
                return -1;

        while (tmp->val != key)
        {
                // last of list. key not matched.
                if (tmp->next == NULL)
                        return -1;
                tmp = tmp->next;
                position++;
        }
        return position;
}

// insert a value after a value in a unique list
void insertAfterAValueUniqueList(Node *&head, int key, int value)
{
        // get the position of the key
        int position = searchByValueUniqueList(head, key);

        // call the appropriate function to insert the value | position + 1 is for Insert After Value.
        if (position != -1)
                insertAtSpecificPos(head, value, position + 1);
        else
        {
                cout << "The value: " << key << " is not present in the list" << endl;
        }
}

// insert a value before a value in a unique list
void insertBeforeAValueUniqueList(Node *&head, int key, int value)
{
        // get the position of the key
        int position = searchByValueUniqueList(head, key);

        // call the appropriate function to insert the value | position - 1 is for Insert Before Value.
        if (position != -1)
                insertAtSpecificPos(head, value, position - 1);
        else
        {
                cout << "The value: " << key << " is not present in the list" << endl;
        }
}

// delete the head node
void deleteAtHead(Node *&head)
{
        Node *tmp = head;
        if (tmp == NULL)
        {
                cout << "There are no nodes in the list" << endl;
                return;
        }

        head = head->next;
        delete tmp;
}

// delete a node from tail
void deleteAtTail(Node *&head)
{
        // to update the previous to the last node's next pointer to null.
        Node *prevNode = NULL;
        Node *currNode = head;

        if (currNode == NULL)
        {
                cout << "There are no nodes in the list" << endl;
                return;
        }

        while (currNode->next != NULL)
        {
                prevNode = currNode;
                currNode = currNode->next;
        }

        // only head node present. not entered into the loop.
        if (prevNode == NULL)
        {
                delete currNode;
                head = NULL;
        }
        else
        {
                // previous to the last node's next - put null.
                prevNode->next = NULL;
                delete currNode;
        }
}

// print the list
void printList(Node *head)
{
        Node *tmp = head;
        while (tmp != NULL)
        {
                cout << tmp->val << " ";
                if (tmp->next != NULL)
                        cout << " -> ";
                tmp = tmp->next;
        }
}

// initialize a list with 5 nodes
void initializeList(Node *&head)
{
        cout << "List Initialization: \n";
        int n = 5;
        for (int i = n; i >= 1; i--)
                insertAtHead(head, i);

        printList(head);
}

// count the number of nodes in the list
int countNode(Node *&head)
{
        Node *tmp = head;
        int count = 0;
        while (tmp != NULL)
        {
                count++;
                tmp = tmp->next;
        }
        return count;
}

// #######################

// show input details.
void show_details()
{
        cout << "Choice 1: InsertAtHead"
             << endl
             << "Choice 2: InsertAtTail"
             << endl
             << "Choice 3: InsertAtSpecificPos"
             << endl
             << "Choice 4: SearchByValUniqueList(unique list)"
             << endl
             << "Choice 5: insert Before A Value UniqueList"
             << endl
             << "Choice 6: insert After A Value UniqueList"
             << endl
             << "Choice 7: Deletion At Head"
             << endl
             << "Choice 8: Deletion At Tail"
             << endl
             << "Choice 9: Print the List"
             << endl
             << "Choice 10: Initialise List with 1 to 5"
             << endl
             << "Choice 11: Count Number Of Node"
             << endl
             << "Choice 12: Show Details"
             << endl
             << "Choice 0: Stop";
}

// main entrypoint of the program
void run()
{
        show_details();

        Node *head = NULL;

        int choice, val, pos, result;

        cout << "\n\nInput Choice: ";
        cin >> choice;

        while (choice != 0)
        {
                switch (choice)
                {
                case 1:
                        cout << "Input the value: ";
                        cin >> val;
                        insertAtHead(head, val);
                        cout << "DONE!\n";
                        break;

                case 2:
                        cout << "Input the value: ";
                        cin >> val;
                        insertAtTail(head, val);
                        cout << "DONE!\n";
                        break;

                case 3:
                        cout << "Input the position (1 based): ";
                        cin >> pos;
                        cout << "Input the value: ";
                        cin >> val;
                        insertAtSpecificPos(head, val, pos);
                        break;

                case 4:
                        cout << "Input the value to search: ";
                        cin >> val;
                        result = searchByValueUniqueList(head, val);
                        if (result != -1)
                                cout << "The value: " << val << " is found at: " << result << " position. \n";
                        else
                                cout << "The value: " << val << " has not been found in the list.\n";
                        break;

                case 5:
                        cout << "Which is the value BEFORE which the new value will be inserted: ";
                        cin >> pos;
                        cout << "Input the value to insert: ";
                        cin >> val;
                        insertBeforeAValueUniqueList(head, pos, val);
                        break;

                case 6:
                        cout << "Which is the value AFTER which the new value will be inserted: ";
                        cin >> pos;
                        cout << "Input the value to insert: ";
                        cin >> val;
                        insertAfterAValueUniqueList(head, pos, val);
                        break;

                case 7:
                        cout << "Deletion at Head\n";
                        deleteAtHead(head);
                        cout << "DONE!\n";
                        break;

                case 8:
                        cout << "Deletion at Tail\n";
                        deleteAtTail(head);
                        cout << "DONE!\n";
                        break;

                case 9:
                        cout << "List print: \n";
                        printList(head);
                        break;

                case 10:
                        initializeList(head);
                        break;

                case 11:
                        result = countNode(head);
                        cout << "Total nodes count are: " << result << endl;
                        break;

                case 12:
                        show_details();
                        break;

                default:
                        break;
                }
                cout << "\n\nNext Choice: ";
                cin >> choice;
        }
        cout << "\nThe list is: \n";
        printList(head);
}

int main()
{
        // call the main entrypoint function.
        run();

        return 0;
}
