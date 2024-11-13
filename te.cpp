#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    while (n)
    {

        s += to_string(n % 2);
        n /= 2;
    }
    reverse(begin(s), end(s));
    cout << s;
}