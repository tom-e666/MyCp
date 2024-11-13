#include <bits/stdc++.h>
using namespace std;
void merge_sort(vector<int> &v, int &a, int &b)
{
    if (b - a < 2)
        return;
    int c = a + (b - a) / 2;
    merge_sort(v, a, c);
    merge_sort(v, c, b);
    merge(v, a, b, c);
}
void merge(vector<int> &v, int &a, int &b, int &c)
{
    int m = c - a;
    int n = b - c;
    int i = a, j = c;
}

int main()
{
    vector<int> v;
    int x;
    while (cin >> x)
    {
        v.emplace_back(x);
    }
    merge_sort(v, 0, v.size() - 1);
}