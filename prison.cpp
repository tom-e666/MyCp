#include <bits/stdc++.h>
using namespace std;
// dung thuat toan loan

const int N = 50;
int m, n; // n dong m cot
int previous[N][N];
int visited[N][N];
int p[N][N];
queue<pair<int, int>> q;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int region = -1;
vector<int> cnt_region{1};
// bac dong nam tay
void flood_fill(int x, int y, int dir)
{
    if (!visited[x][y])
    {
        previous[x][y] = ++region;
        cnt_region.push_back(1);
    }

    if (dir >= 8)
    {
        dir -= 8;
    }
    else
    {
        // move
        if (x - 1 >= 0 && !visited[x - 1][y])
        {
            visited[x - 1][y] = 1;
            previous[x - 1][y] = previous[x][y];
        }
    }
    if (dir >= 4)
    {

        dir -= 4;
    }
    else
    {
        if (y + 1 < m && !visited[x][y + 1])
        {
            visited[x][y + 1] = 1;
            previous[x][y + 1] = previous[x][y];
        }
    }
    if (dir >= 2)
    {
        dir -= 2;
    }
    else
    {
        if (x + 1 < n && !visited[x + 1][y])
        {
            visited[x + 1][y] = 1;
            previous[x + 1][y] = previous[x][y];
        }
    }
    if (dir >= 1)
    {
        dir -= 1;
    }
    else
    {
        if (y - 1 >= 0 && !visited[x][y - 1])
        {
            visited[x][y - 1] = 1;
            previous[x][y - 1] = previous[x][y];
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> p[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            bfs(i, j, p[i][j]);
        }
    // a
    cout << region << "\n";
}