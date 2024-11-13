#include <bits/stdc++.h>
using namespace std;
#define INF 1e9 + 100
int n, s, p;
vector<int> num;
vector<int> mem;
int get_it(int x)
{
    if (mem[x] != -1)
        return mem[x];
    int res = INF;
    for (auto c : num)
    {
        if (x - c >= 0)
            res = min(res, get_it(x - c) + 1);
    }
    mem[x] = res;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s >> p;
    num.resize(n);
    mem.resize(s + 1, -1);
    mem[0] = 0;
    for (auto &i : num)
        cin >> i;
    int x = get_it(s);
    if (x != INF)
    {
        cout << x * p;
    }
    else
    {
        cout << "-1";
    }
}