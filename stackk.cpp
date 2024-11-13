#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> temper;
    int x;
    while (cin >> x)
        temper.emplace_back(x);
    int n = temper.size();
    vector<int> res(n, 0);
    stack<int> s;
    for (int i = n - 1; i >= 0; --i)
    {
        while (!s.empty() && temper[i] >= temper[s.top()])
        {
            s.pop();
        }
        if (!s.empty())
        {
            res[i] = s.top() - i;
        }
        s.push(i); // so this one push ele_pos to stack, if the top is not okay, then clear it out;
    }
    for (auto i : res)
        cout << i << ' ';
}
