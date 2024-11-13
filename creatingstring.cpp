#include<bits/stdc++.h>
using namespace std;

set<string> ans;

void permutate(vector<char>& v, int start, int end) {
    if (start == end) {
        ans.insert(string(v.begin(), v.end()));
        return;
    }

    for (int i = start; i <= end; ++i) {
        if (i > start && v[i] == v[start]) {
            continue;  // Skip consecutive duplicate characters
        }

        swap(v[start], v[i]);
        permutate(v, start + 1, end);
        swap(v[start], v[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    vector<char> v(s.begin(), s.end());
    sort(begin(v), end(v));

    permutate(v, 0, v.size() - 1);

    cout << ans.size() << "\n";
    for (const string& str : ans) {
        cout << str << "\n";
    }

    return 0;
}
