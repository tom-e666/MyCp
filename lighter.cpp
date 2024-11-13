#include <bits/stdc++.h>
using namespace std;
int m, n, k;
int Try(int x, int y, int k)
{
    // x,y as size
    if (x == 0 || y == 0)
        return 0;
    if (x == 1 || y == 1)
        return ceil(1.0 * x * y / k);
    if (x >= k)
    {
        return ceil(1.0 * y / k) * (x / k) + Try(x % k, y, k);
    }
    else if (y >= k)
    {
        swap(x, y);
        return ceil(1.0 * y / k) * (x / k) + Try(x % k, y, k);
    }
    else
    {
        return ceil(1.0 * max(x, y) / k);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin >> m >> n >> k;
    cout << Try(m, n, k);
}
