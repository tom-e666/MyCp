#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct st {
    string s;
    ll cost;

    
    bool operator <(const st& o) const {
        return cost > o.cost;
    }
};

unordered_map<string, ll> mp;
priority_queue<st> pq;  
string init;
string res;
int n;
vector<ll>w;
bool search() {
    if (pq.empty()) return false;

    st cur = pq.top();
    pq.pop();

    string s = cur.s;
    ll wt = cur.cost;
    if (s == res) {
        cout << cur.cost;
        return true;
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(s[i], s[j]);

            
            ll neww = wt + w[s[i] - '0'] + w[s[j] - '0'];
            if (mp[s] == 0 || neww < mp[s]) {
                mp[s] = neww;
                pq.push({s, neww});
            }
            swap(s[i], s[j]);
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    w.resize(n);
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    char c;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        init += to_string(c - '0');
    }
    for (int i = 0; i < n; ++i) {
        cin >> c;
        res += to_string(c - '0');
    }
    pq.push({init, 0});
    mp[init] = 0;
    while (!search()) {}
    return 0;
}
