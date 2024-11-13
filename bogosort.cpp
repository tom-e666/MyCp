// bogosort/permutationsort/studpidsort/ another implementation use random?
#include <bits/stdc++.h>
#include <random>
#include <algorithm>
using namespace std;
bool isSorted(vector<int> &v)
{
    if (!v.size())
        return true;
    int i = v.size() - 1;
    while (i && v[i - 1] <= v[i])
        i--;
    if (i)
        return false;
    return true;
}

void stupidsort(vector<int> &v, int i) // though all permutation
{
    if (i == v.size())
    {
        for (auto i : v)
            cout << i << " ";
        if (isSorted(v))
            cout << "sorted\n";
        else
            cout << "not sorted\n";
        return;
    }
    for (int j = i; j < v.size(); ++j) // Change ++i to ++j
    {
        swap(v[i], v[j]);
        stupidsort(v, i + 1);
        swap(v[i], v[j]);
    }
}
void randomsort(vector<int> &v)
{
    random_device rd;
    mt19937 g(rd());
    while (!isSorted(v))
    {
        shuffle(v.begin(), v.end(), g);
        for (auto i : v)
            cout << i << " ";
        cout << "\n";
    }
}

int main()
{
    vector<int> v;
    int x;
    while (cin >> x)
    {
        v.emplace_back(x);
    }
    // stupidsort(v, 0);
    randomsort(v); // do not insert sorted array eg 1 2 3 4
}