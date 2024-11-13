#include <bits/stdc++.h>
using namespace std;
void print(int a, int b)
{
    cout << "(" << a << "," << b << ")";
}

int main()
{
    int n;
    vector<int> x;
    vector<int> y;
    int a, b;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }

    int pos = 0;
    int min_distance = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        int distance = x[i] * x[i] + y[i] * y[i];
        if (distance < min_distance)
        {
            pos = i;
            min_distance = distance;
        }
        else if (distance == min_distance && y[i] > y[pos])
        {
            pos = i;
        }
    }
    print(x[pos], y[pos]);
    cout << endl;

    // Find two points farthest apart
    int res1 = 0, res2 = 1;
    double max_distance = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            double distance = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
            if (distance > max_distance)
            {
                max_distance = distance;
                res1 = i;
                res2 = j;
            }
        }
    }
    print(x[res1], y[res1]);
    cout << " ";
    print(x[res2], y[res2]);
    cout << endl;

    // Check if any two points are parallel to the x-axis
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (y[i] == y[j])
            {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";

    return 0;
}
