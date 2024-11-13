#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> res;
    string s;
    while (cin >> s)
    {
        for (auto &i : s)
        {
            i = tolower(i);
        }
        res.emplace_back(s);
    }
    int i = res.size();
    for (int i = 0; i < n - 1; ++i)
    {
        cout << res[i] << " ";
    }
    cout << res[n - 1];
}