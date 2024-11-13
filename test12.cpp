#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vll vector<vector<long long>>
#define fi first
#define se second
#define vi vector<int>
#define loop(i,a,b) for(int i=a;i<b;++i)
#define all(x) (x).begin(),(x).end()
#pragma GCC optimize("O3")
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n,x;
    cin>>n>>x;
    ll v[n];
    cin>>v[0];
    for(int i=1;i<n;++i)
    {
        cin>>v[i];
        v[i]+=v[i-1];
    }
    pll vv[n];
    for(int i=0;i<n;++i)
    {
        vv[i].fi=v[i];
        vv[i].se=i;
    }
    sort(vv,vv+n,[](pll &a, pll &b)
    {
        if(a.fi==b.fi)
            return a.se>b.se;
        return a.fi<b.fi;
    });
    ll vvv[n];
    for(int i=0;i<n;++i)
    {
        vvv[i]=vv[i].fi;
    }
    ll cnt=0;
    for(int i=0;i<n;++i)
    {
        if(v[i]==x) cnt++;
        ll s=x+v[i];
        auto p=lower_bound(vvv,vvv+n,s)-vvv;
        if(p==n || vvv[p]!=s) continue;
        else
        {
            //p is index of vv too
            while(p<n && vv[p].fi==s && vv[p].se>i  )
            {
                p++;
                cnt++;
            }
        }
    }
    cout<<cnt;



    
    
}