/*tim chu, not optimiized version*/
#include <bits/stdc++.h>
using namespace std;
int m, n, x, y;
string z;
int sz;
vector<vector<bool>> visited;
vector<vector<char>> mtrx;
string res;
vector<int> dx{0, 1, 0, -1};
vector<int> dy{1, 0, -1, 0};
bool found = false;
vector<int> trail;
void baktrack(int th, int X, int Y)
{
    if (found)
        return;

    res += mtrx[X][Y];
    if (res.size() == sz)
    {
        if (res == z)
        {
            found = true;
            trail.emplace_back(X);
            trail.emplace_back(Y);
        }
    }
    for (int i = 0; i < 4; ++i)
    {
        int xx = X + dx[i];
        int yy = Y + dy[i];
        if (xx >= 0 && xx < m && yy >= 0 && yy < n && !visited[xx][yy])
        {
            visited[xx][yy] = true;
            baktrack(th + 1, xx, yy);
            visited[xx][yy] = false;
        }
    }
    res.pop_back();
}
int main()
{
    cin >> m >> n >> x >> y >> z;
    sz = z.size();
    visited.resize(m, vector<bool>(n));
    mtrx.resize(m, vector<char>(n));
    for (auto &line : mtrx)
        for (auto &c : line)
            cin >> c;
    visited[x][y] = true;
    baktrack(0, x, y);
    if (found)
    {
        cout << "YES\n";
        cout << "(" << trail[0] << "," << trail[1] << ")";
    }
    else
    {
        cout << "NO";
    }
}