#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull expo(ull X, ull N, ull m)
{
    if (N == 0)
        return 1;

    ull Y = expo(X, N / 2, m);
    if (N % 2 == 0)
    {
        return (Y * Y) % m;
    }
    else
    {
        return (((Y * Y) % m) * X) % m;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ull a, b, n, m;
    cin >> a >> b >> n >> m;

    ull res = (expo(a, n, m) + expo(b, n, m)) % m;
    cout << res;

    return 0;
}
