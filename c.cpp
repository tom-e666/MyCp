#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    int cnt = 0;
    while (n--)
    {
        string s;
        getline(cin, s);
        bool flag = false; // stage
        for (auto i : s)
        {
            if (isspace(i))
            {
                if (!flag)
                {
                    cnt++;
                    flag = true;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                flag = false;
            }
        }
    }
    cout << cnt;
}