#include <bits/stdc++.h>
using namespace std;
bool div_and_con(const string &s)
{
    if (s.size() == 1)
        return false;
    if (s.size() == 0)
        return true;
    int c = s[0];
    auto it = find(1 + s.begin(), s.end(), c);
    while (it != s.end())
    {
        if (div_and_con(string(1 + s.begin(), it)) && div_and_con(string(1 + it, s.end())))
        {
            return true;
        }
        it = find(it + 1, s.end(), c);
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    int res = 0;
    string s;
    stringstream ss;
    while (n--)
    {
        cin >> s;
        if (div_and_con(s))
        {
            res++;
            ss << s << "\n";
        }
    }
    cout << res << "\n"
         << ss.str();
}