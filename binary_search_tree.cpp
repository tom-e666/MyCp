#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;

    int res = 0;
    for (auto c : s)
    {
        if (isdigit(c))
        {
            res += c;
        }
        else
        {
            res += 10 + (c - 'A');
        }
    }
    string ss;
    while (res)
    {
        ss += to_string(res % 2);
        res /= 2;
    }
    cout << ss;
}