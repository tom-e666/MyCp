#include <bits/stdc++.h>
/* backtraking kết hợp với lưu dấu đống nấm, thực hiện
bằng cách duy trì tích của các số 1-3: 2,3,5, -> f chia hết ít nhất 2 số*/
// hoặc sử dụng bitwise?
using namespace std;
vector<vector<int>> v;
vector<int> dx{1, 0};
vector<int> dy{0, 1};
int m, n;
int cnt = 0;
void backtrack(int x = 0, int y = 0, int mush = 0)
{
    if (x == m - 1 && y == n - 1)
    {
        if (__builtin_popcount(mush) >= 3)
            cnt++;
        return;
    }
    if (v[x][y] == -1)
        return;
    mush |= (1 << v[x][y]);
    for (int i = 0; i < 2; ++i)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < m && yy < n)
        {
            backtrack(xx, yy, mush);
        }
    }
}
int main()
{
    cin >> m >> n;
    v.resize(m, vector<int>(n));
    for (auto &line : v)
        for (auto &i : line)
            cin >>
                i;
    backtrack();
    if (cnt)
    {
        cout << cnt;
    }
    else
    {
        cout << "-1";
    }
}