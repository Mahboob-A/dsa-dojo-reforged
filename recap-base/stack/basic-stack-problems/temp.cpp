#include <bits/stdc++.h>

using namespace std;

void reverseWords(string &str)
{
        int n = str.length();
        int start = 0, end = 0;

        // Reverse the entire string
        reverse(str.begin(), str.end());

        while (end < n)
        {
                // Move end to the end of the word
                while (end < n && isalpha(str[end]))
                {
                        end++;
                }

                // Reverse the current word
                reverse(str.begin() + start, str.begin() + end);

                // Move to the next word
                start = ++end;
        }
}

int main()
{
        string str = "Hello how are you[]";
        reverseWords(str);
        cout << "\nafter reverse: " << endl; 
        cout << str << endl;
        return 0;
}
