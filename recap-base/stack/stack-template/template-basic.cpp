
// 050824, Monday, 09.00 am

#include <bits/stdc++.h>
using namespace std;


// Template basic. 
template <typename T> T myMax(T a, T b)
{
        return a > b ? a : b;
}

void sol()
{

        cout << myMax<int>(10, 20) << endl;
        cout << myMax<float>(5.8, 23.1) << endl;
        cout << myMax<char>('g', 'q') << endl;
}

int main()
{

        sol();

        return 0;
}