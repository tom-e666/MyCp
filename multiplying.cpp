#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll m = 10000000;
ll multiply(ll a, ll b)
{
    ll result = 0;
    while (b > 0)
    {
        if (b & 1)
            result += a;
        a <<= 1;
        b >>= 1;
    }
    return result;
}
int main()
{
    ll a, b;
    cin >> a >> b;
    cout << multiply(a, b);
}