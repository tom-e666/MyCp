#include <bits/stdc++.h>
using namespace std;
int h[1003][1003];
bool pumped[1003][1003];
vector<pair<int, int>> p;
vector<int> amount;
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int m, n;
void pumpint(int x, int y)
{
    int am=1;
    p.push_back({x, y});
    int s = h[x][y];
    pumped[x][y] = 1;
    for (int i = 0; i < 7; ++i)
    {
        if (x + dx[i] >= 0 && x + dx[i] < m && y + dy[i] >= 0 && x + dy[i] < n && s >= h[x + dx[i]][y + dy[i]])
        {
            pumped[x + dx[i]][y + dy[i]] = 1;
            am++;
        }
    }
    amount.push_back(am);
}

int find_pump(int x, int y)
{
    int ax = x, ay = y;
    int s = h[x][y];
    for (int i = 0; i < 7; ++i)
    {
        if (x + dx[i] >= 0 && x + dx[i] < m && y + dy[i] >= 0 && x + dy[i] < n && s <= h[x + dx[i]][y + dy[i]])
        {
            ax = x + dx[i];
            ay = y + dy[i];
            s = h[ax][ay];
        }
    }
    pumpint(ax, ay);
}

int main()
{

    cin >> m >> n;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> h[i][j];

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
        {
            if (!pumped[i][j])
            {
                find_pump(i, j);
            }
        }
    cout << p.size() << "\n";
    for (auto px : p)
        cout << px.first << "-" << px.second << endl;
    auto it=max_element(amount.begin(),amount.end());
    int dis=distance(it,amount.begin());
    cout<<p[dis].first<<" "<<p[dis].second<<" "<<*it;
}