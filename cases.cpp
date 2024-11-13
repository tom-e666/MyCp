#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int bin_search(int x)
{
}
int main()
{
    ios_base::sync_with_stdio(0);
    int q, n, x;
    cin >> n;
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    cin >> q;
    while (q--)
    {
        cin >> x;
        int l = 0, r = n - 1;
        int res = n - 1;
        for (int p = n / 2; p > 0; p /= 2)
        {
            while (res - p >= 0 && v[res - p] >= x)
                res -= p;
        }
        if (v[res] == x)
        {
            cout << "Yes"
                 << " " << res + 1 << "\n";
        }
        else
        {
            cout << "No"
                 << " " << res + 1 << "\n";
        }
    }
}