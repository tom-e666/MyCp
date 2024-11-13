#include <bits/stdc++.h>
using namespace std;
int n, l, r;
vector<int> v;

int slicce(int l, int r, bool ismax = true)
{
    if (l == r)
        return v[l];
    int m = l + (r - l) / 2;
    if (ismax)
    {
        return max(slicce(l, m, ismax), slicce(m + 1, r, ismax));
    }
    else
    {
        return min(slicce(l, m, ismax), slicce(m + 1, r, ismax));
    }
}

int main()
{
    cin >> n >> l >> r;
    l -= 1;
    r -= 1;
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    cout << slicce(l, r, false) << "\n";
    cout << slicce(l, r) << "\n";
}