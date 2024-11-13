#include <bits/stdc++.h>
using namespace std;
// ternary split
int main()
{
    vector<int> v;
    sort(v.begin(), v.end());
    for (int i = 0; i < (1 << v.size()); ++i)
    {
        // y12
        for (int j = 0; j < (1 << i); ++j)
        {
            // x1 x2
            int pos = 0;
            int x1 = 0;
            int x2 = 0;
            while (j)
            {
                if (j ^ 0)
                    x1 += v[pos];
                else
                    x2 += v[pos];
                pos++;
            }
        }
    }
}