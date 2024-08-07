
// Recap Basics: 050824, Monday, 10.00 am

#include <bits/stdc++.h>
#include "stack-template.h"

using namespace std;

void sol()
{
        // Stack<int> st;

        // Stack<float> st;

        // Stack<char> st;

        Stack<string> st;

        // Stack<pair<int, string>> st;

        // Push
        cout << "\n\nPush Operation.\n";
        
        // st.push(1);
        // st.push(2);
        // st.push(3);
        // st.push(4);

        // st.push(1.5);
        // st.push(2.0);
        // st.push(3.1);
        // st.push(4.6);

        // st.push('a');
        // st.push('b');
        // st.push('c');
        // st.push('d');

        st.push("india");
        st.push("palestine");
        st.push("bangladesh");
        st.push("world");

        // st.push(make_pair(1, "Mahboob Alam"));
        // st.push(make_pair(2, "Yurious"));
        // st.push(make_pair(3, "Cpp"));
        // st.push(make_pair(4, "Python"));

        // st.push({1, "Mahboob Alam"});
        // st.push({2, "Yurious"});
        // st.push({3, "Cpp"});
        // st.push({4, "Python"});

        cout << "\nSize Operation After Push.\n";
        cout << st.size() << endl;

        cout << "\nTop Operation After Push.\n";
        cout << st.Top() << endl;

        // Pop
        cout << "\n\nPop Operation. Poped 2 times.\n";
        st.pop();
        st.pop();
        // st.pop();
        // st.pop();

        cout << "\nSize Operation Aftr Pop\n";
        cout << st.size() << endl;

        cout << "\nTop Operation After Pop.\n";
        cout << st.Top() << endl;

        // Empty
        cout << "\n\nEmpty Operation.\n";
        cout << st.empty() << endl;

        if (st.empty())
                cout << "\nStack is empty. \n"
                     << endl;
        else
                cout << "\nStack is not empty\n"
                     << endl;
}

int main()
{

        sol();

        return 0;
}