#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vll vector<vector<long long>>
#define fi first
#define se second

#define loop(i,a,b) for(int i=a;i<b;++i)
#define all(x) (x).begin(),(x).end()
#pragma GCC optimize("O3")
using namespace std;

ll n, m;

bool Try(ll t, const ll v[]) {
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += t / v[i];
        if (cnt >= m) return true;  
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    ll v[n];
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    ll t = 0;
    ll p=(*min_element(v,v+n))*m;
    for (; p > 0; p /= 2) {
        while (!Try(t + p, v)) t += p;
    }
    cout << t + 1;
}
