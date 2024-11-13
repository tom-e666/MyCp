#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while (getline(cin, s))
    {
        for (auto c : s)
            if (c != '.')
                cout << c;
        cout << "@student.hcmue.edu.vn\n";
    }
}