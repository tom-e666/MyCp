#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n>>m;
    
    map<int, int> mp; // position in des
    vector<int> val(n,0);
    int x;
    
    for (int i = 0; i < n; ++i) {
        cin >> x;
        mp[x] = i;
        val[i]=x;
    }

    int cnt = 1;
    auto it = mp.begin(); // Start from the beginning of the map

    for (++it; it != mp.end(); ++it) {
        if (it->second < prev(it)->second) {
            cnt++;
        }
    }

    cout << cnt<<"\n";
    {
        int x,y;
        int a,b;
    while(m--){
        cin>>x>>y;
        a=val[x];
        b=val[y];
        val[x]=b;
        val[y]=a;
        pos


    }

    return 0;
    }
}
