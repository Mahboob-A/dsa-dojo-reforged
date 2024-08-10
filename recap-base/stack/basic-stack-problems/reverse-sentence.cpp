
// Recap Basics: 070824, Wednesday, 10.00 am

#include <bits/stdc++.h>
#include "stack-template.h"

using namespace std;

void sol()
{

        stack<string> st;

        string str = "Hello how are  you ";

        string new_str;
        for (int i = 0; i < str.length(); i++)
        {
                if ((str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122) && str[i] != ' ')
                {
                        new_str += str[i];
                }
                else
                {
                        // cout << "In else: " << new_str << endl;
                        if (new_str != "")
                        {
                                st.push(new_str);
                                new_str = "";
                        }
                }

                if (i == str.length() - 1)
                {
                        // cout << "\nnew str: " << new_str;
                        st.push(new_str);
                }
        }

        cout << endl
             << endl;
        while (!st.empty())
        {
                string str = st.top();
                st.pop();
                cout << str << " ";
        }
        cout << endl
             << endl;
}

int main()
{


        sol();

        return 0;
}