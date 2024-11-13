#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int lim = 1e6 + 1;

int main()
{
    vector<bool> is_ele(lim, true);
    vector<int> divisor(lim, 1);
    is_ele[0] = is_ele[1] = false;

    for (int i = 2; i < lim; i++)
    {
        if (is_ele[i])
        {
            for (int j = i + i; j < lim; j += i)
            {
                is_ele[j] = false;
                if (divisor[j] == 1)
                    divisor[j] = i;
            }
        }
    }

    long long n;
    cin >> n;

    map<long long, int> res;
    long long limsq = sqrt(n);

    // for (int i = 2; i <= limsq; ++i)
    // {
    //     while (i < lim && !is_ele[i])
    //         i++;
    //     if (i == lim)
    //         break;
    //     while (n % i == 0)
    //     {
    //         res[i]++;
    //         n /= i;
    //     }
    // }

    // faster rooting with divisor:
    while (n > 1e6)
    {
        for (int i = 2; i <= limsq; ++i)
        {
            while (i < lim && !is_ele[i])
                i++;
            if (i == lim)
                break;
            while (n % i == 0)
            {
                res[i]++;
                n /= i;
            }
            if (n <= 1e6)
                break;
        }
    }
    if (n > 1e6)
        goto escape;
    while (divisor[n] != 1)
    {
        res[divisor[n]]++;
        n /= divisor[n];
    }
escape:
    if (n > 1)
        res[n]++;

    for (auto pr : res)
    {
        cout << pr.first << " " << pr.second << "\n";
    }

    return 0;
}
