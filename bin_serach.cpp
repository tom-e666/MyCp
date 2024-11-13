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


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //alike LIS technique
    ll n;
    cin>>n;
    ll a[n]{LLONG_MAX};
    ll x;
    for(int i=0;i<n;++i)
    {
    	cin>>x;
    	auto p=upper_bound(a,a+n,x)-a;
    	if(a[p]==INF)
    	{
    		a[p]=x;
    	}else
    	{
    		
    	}
    }

}
