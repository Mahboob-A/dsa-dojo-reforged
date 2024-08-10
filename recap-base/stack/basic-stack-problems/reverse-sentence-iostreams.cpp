
// 100824, Saturday, 11.00 am

#include <bits/stdc++.h>
using namespace std;

// Reverse String using String Stream

void sol()
{

        string inp_str = "Hello how are you!";

        vector<string> words;
        string word;

        // input stream (makes the string just like the string is being read from input stream)
        istringstream iss(inp_str); // iss => input string stream

        while (iss >> word) // take the word from the input stream
        {
                words.push_back(word);
        }

        // original: ["Hello", "how", "are", "you"]

        // reversed: ["you", "are", "how", "Hello"]
        reverse(words.begin(), words.end());

        // output stream (an output stream, that allows to write string as if the real output stream)
        ostringstream oss; // oss => output string stream

        for (const auto &w : words)
        {
                oss << w; // write the word to the output stream

                if (&w != &words.back())
                {
                        oss << ' '; // put an whisespace between words until the current and the last word in the vector is same.
                }
        }

        string reversed_str = oss.str();

        cout << "\nOriginal String: " << inp_str << endl
             << endl;
        cout << "\nReversed String: " << reversed_str << endl
             << endl;
}

int main()
{

        sol();

        return 0;
}