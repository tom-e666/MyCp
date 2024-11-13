#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    vector<int> v;
    while (cin >> n)
        v.emplace_back(n);
    sort(begin(v), end(v));
    int sz = v.size();
    sz = (v.size() / 2) * 2;
    for (int i = 0; i < sz; i += 2)
    {
        cout << v[i + 1] << " " << v[i] << " ";
    }
    if (sz != v.size())
    {
        cout << "0 " << v.back();
    }
}
