#include <bits/stdc++.h>
using namespace std;
int main()
{
    // kardane implementation
    vector<int> v;
    int x;
    while (cin >> x)
    {
        v.emplace_back(x);
    }

    int max_till_now = INT_MIN, max_at_here = 0;
    int start = 0, end = 0, s = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        max_at_here += v[i];
        if (max_till_now < max_at_here)
        {
            max_till_now = max_at_here;
            start = s;
            end = i;
        }

        if (max_at_here < 0)
        {
            max_at_here = 0;
            s = i + 1;
        }
    }
    cout << max_till_now << "\n"
         << start << " " << end;
}
