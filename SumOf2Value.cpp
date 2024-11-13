#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> v(n, 0);
    for (auto &i : v)
        cin >> i;

    decltype(v) vv(begin(v), end(v));
    sort(begin(v), end(v));

    int i = 0, j = n - 1;
    while (i < j) {
        if (v[i] + v[j] < x) {
            i++;
        } else if (v[i] + v[j] > x) {
            j--;
        } else {
            int pos1 = find(vv.begin(), vv.end(), v[i]) - vv.begin();
            int pos2 = find(vv.rbegin(), vv.rend(), v[j]).base() - vv.begin()-1;
            
            cout << min(pos1, pos2) + 1 << " " << max(pos1, pos2) + 1;
            return 0;
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}
