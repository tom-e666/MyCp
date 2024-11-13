#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
stringstream ss;
string solution;
int n;
string encode[] = {"X", "P", "T", "L"};
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
void Try(int x, int y)
{
    if (x == n - 1 && y == n - 1)
    {
        ss << solution << "\n";
    }
    else
    {
        for (auto i = 0; i < 4; ++i)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx>-1 && xx<n && yy>-1 && yy<n)
        }

    }
}
int main()
{
    cin >> n;
    v.resize(n, vector<int>(n));
    for (auto &line : v)
        for (auto &mem : line)
            cin >> mem;
}