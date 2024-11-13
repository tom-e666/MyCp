#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    map<int, int> mp; // position in des
    int x;
    
    for (int i = 0; i < n; ++i) {
        cin >> x;
        mp[x] = i;
    }

    int cnt = 1;
    auto it = mp.begin(); // Start from the beginning of the map

    for (++it; it != mp.end(); ++it) {
        if (it->second < prev(it)->second) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
