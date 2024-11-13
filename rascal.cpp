#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

void leftlineConvert(vi &s, const vi &guidance)
{
    vi a;
    vi b;
    for(int i = 0; i < guidance.size(); ++i)
    {
        if(guidance[i])
            a.push_back(s[i]);
        else
            b.push_back(s[i]);
    }
    s = a;
    s.insert(s.end(), b.begin(), b.end());
}

void rightlineConvert(vi &s, const vi &guidance)
{
    vi a;
    vi b;
    for(int i = 0; i < guidance.size(); ++i)
    {
        if(guidance[i])
            a.push_back(s[i]);
        else
            b.push_back(s[i]);
    }
    s = b;
    s.insert(s.end(), a.begin(), a.end());
}

void fitGuidance(vi &guidance, int size)
{
    if(guidance.size() < size)
        guidance.resize(size, 0);
}


void Rotate(vvi &vec)
{
    if(vec.empty()) return;
    vvi res(vec[0].size(), vi(vec.size()));
    for(int i = 0; i < vec.size(); ++i)
        for(int j = 0; j < vec[0].size(); ++j)
        {
            res[j][vec.size() - 1 - i] = vec[i][j];
        }
    vec = res;
}

void gridConvert(vvi &s, const vvi &guidance, const string &orientation)
{
    vvi localGuidance = guidance;
    for(auto &g : localGuidance)
        fitGuidance(g, s[0].size());
        
    if(orientation == "left")
    {
        for(int i = 0; i < s.size(); ++i)
        {
            leftlineConvert(s[i], localGuidance[i]);
        }
    }
    else if(orientation == "right")
    {
        for(int i = 0; i < s.size(); ++i)
        {
            rightlineConvert(s[i], localGuidance[i]);
        }
    }
    else if(orientation == "up")
    {
        Rotate(s);
        for(int i = 0; i < s.size(); ++i)
        {
            leftlineConvert(s[i], localGuidance[i]);
        }
        Rotate(s);
        Rotate(s);
        Rotate(s);
    }
    else if(orientation == "down")
    {
        Rotate(s);
        for(int i = 0; i < s.size(); ++i)
        {
            rightlineConvert(s[i], localGuidance[i]);
        }
        Rotate(s);
        Rotate(s);
        Rotate(s);
    }
}

int main()
{
    int n, m;
    cin >> n >> m; // Input size of grid
    vvi grid(n, vi(m));
    vvi guidance(n, vi(m));

    // Input grid
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> grid[i][j];

    // Input guidance
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> guidance[i][j];

    string orientation;
    cin >> orientation;

    gridConvert(grid, guidance, orientation);

    // Output the result
    for(const auto &row : grid)
    {
        for(const auto &elem : row)
            cout << elem << " ";
        cout << endl;
    }

    return 0;
}
