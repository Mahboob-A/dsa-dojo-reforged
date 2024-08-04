
// 040824, Sunday, 10.00 am

#include <bits/stdc++.h>
#include "mystack.h"

using namespace std;

void sol()
{

        Stack st;

        // Push
        cout << "\n\nPush Operation. Pushed 1, 2, 3, 4\n";
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);

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