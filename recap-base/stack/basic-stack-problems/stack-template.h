
// 040824, Sunday, 10.00 am

#include <bits/stdc++.h>
using namespace std;

template <typename N>
class Node
{
public:
        N value;
        Node *next;
        Node *prev;

        Node(N val)
        {
                this->value = val;
                next = NULL;
                prev = NULL;
        }
};

template <typename S>
class Stack
{

        int count = 0;
        Node<S> *head;
        Node<S> *top;

public:
        Stack()
        {
                head = NULL;
                top = NULL;
        }

        void push(S val)
        {
                Node<S> *newNode = new Node<S>(val);

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

        S pop()
        {

                Node<S> *tmp = top;
                S returnVal;

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

        S Top()
        {
                S returnVal;
                if (head == NULL)
                {
                        return returnVal;
                }
                returnVal = top->value;
                return returnVal;
        }
};
