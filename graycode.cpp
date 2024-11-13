#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<string> a = {"0", "1"};

    for (int i = 2; i <= n; ++i) {
        vector<string> b(a);
        for (string &str : b) {
            str = "1" + str;
        }
        for (string &str : a) {
            str = "0" + str;
        }
        a.insert(a.end(), b.rbegin(), b.rend());
    }

    for (const auto &s : a) {
        cout << s << "\n";
    }

    return 0;
}
