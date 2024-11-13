#include <bits/stdc++.h>
using namespace std;
vector<long long> ficc{1, 1};
vector<long long> prime{2, 3, 5};
int main()
{
    int n;
    cin >> n;
    long long x = 2;
    int i = 0;
    while (x <= n)
    {
        x = ficc[i] + ficc[++i];
        ficc.emplace_back(x);
    }
    x = 7;
    while (x <= n)
    {
        bool check = false;
        for (auto i : prime)
        {
            if (i * i > x)
                break;
            if (x % i == 0)
            {
                check = true;
                break;
            }
        }
        if (!check){
            prime.emplace_back(x);
        }
        x+=2;
    }
    for (auto c : ficc)
    {
        if (binary_search(prime.begin(), prime.end(), c))
            cout << c << "\n";
    }
}