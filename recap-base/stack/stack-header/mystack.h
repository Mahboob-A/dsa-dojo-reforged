
// 040824, Sunday, 10.00 am

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
        int value;
        Node *next;
        Node *prev;

        Node(int val)
        {
                this->value = val;
                next = NULL;
                prev = NULL;
        }
};

class Stack
{

        int count = 0;
        Node *head;
        Node *top;

public:
        Stack()
        {
                head = NULL;
                top = NULL;
        }

        void push(int val)
        {
                Node *newNode = new Node(val);

                if (head == NULL)
                {
                        head = top = newNode;
                        count++;
                        return;
                }

                top->next = newNode;
                newNode->prev = top;
                top = newNode;
                count++;
        }

        int pop()
        {

                Node *tmp = top;
                int returnVal = -1;

                if (head == NULL)
                {
                        cout << "Stack Underflow" << endl;
                        return returnVal;
                }

                if (head == top)
                {
                        head = top = NULL;
                }
                else
                {
                        top = tmp->prev;
                        top->next = NULL;
                }

                returnVal = tmp->value;
                delete tmp;
                count--;
                return returnVal;
        }

        bool empty()
        {
                if (head == NULL)
                        return true;
                else
                        return false;
        }

        int size()
        {
                return count;
        }

        int Top()
        {
                int returnVal = -1;
                if (head == NULL)
                {
                        return returnVal;
                }
                returnVal = top->value;
                return returnVal;
        }
};
