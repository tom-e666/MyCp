#include<bits/stdc++.h>
using namespace std;
#define all(x) begin(x),end(x)

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin >> n >> x;
    vector<int> v(n);
    for(auto &i: v) cin >> i;
    multimap<int,int> mp;
    for(int i=0;i<n;++i) mp.emplace(v[i],i);
    sort(all(v));
    int l=0, r=n-1;
    long long s=0;
    while(l < r - 1){
        s = v[l] + v[r];
        if(l == r - 2){
            if(v[l] + v[l+1] + v[l+2] == x){
                cout << mp.find(v[l])->second + 1 << " ";
                mp.erase(mp.find(v[l]));
                cout << mp.find(v[l+1])->second + 1 << " ";
                mp.erase(mp.find(v[l+1]));
                cout << mp.find(v[l+2])->second + 1;
                return 0;
            } else {
                break;
            }
        }
        auto m = prev(upper_bound(v.begin() + l + 1, v.begin() + r, x - s));
        if(m == v.begin() + l){
        	
            r--;
        } else if(m == v.begin() + r - 1){
            l++;
        } else {
            cout << mp.find(v[l])->second + 1 << " ";
            cout << mp.find(*m)->second + 1 << " ";
            cout << mp.find(v[r])->second + 1;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
}
