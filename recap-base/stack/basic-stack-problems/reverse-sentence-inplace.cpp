
// 100824, Saturday, 11.00 am

#include <bits/stdc++.h>
using namespace std;

void sol()
{

        string str = "Hello how are you!";

        cout << "\nOriginal String: " << str << endl;

        int n = str.length();

        int start = 0, end = 0;

        // !uoy era woh olleH
        reverse(str.begin(), str.end());

        while (end < n)
        {
                // take one word from the reversed string 
                while (end < n && isalpha(str[end]))
                {
                        end++;
                }

                // reverse the one word from the string from: " !uoy " to => " !you "
                reverse(str.begin() + start, str.begin() + end);

                // and then move the start to forward 
                start = ++end;
        }

        cout << "\nReversed String: " << str << endl;
}

int main()
{

        // string str = "Hello how are you!";

        // reverse(str.begin(), str.end());

        // cout << str << endl; 
        
        sol();

        return 0;
}