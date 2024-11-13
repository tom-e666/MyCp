#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define vll vector<vector<long long>>
#define fi first
#define se second
#define loop(i,)
using namespace std;
#pragma GCC optimize("03")
const int INF=1e9+7;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll sz, m,n;
	cin>>sz>>m>>n;
	pll  l[m],r[n];
	for(int i=0;i<m;++i) cin>>l[i].fi;
	for(int i=0;i<m;++i) cin>>l[i].se;
	for(int i=0;i<n;++i) cin>>r[i].fi;
	for(int i=0;i<n;++i) cin>>r[i].se;	
	sort(l,l+m);
	sort(r,r+n);
	//store index, cal sum;
	ll prefl[m],prefr[n];//pref[l]: value may be at some stick
	ll pl[m],pr[n];//in ascending order
	prefl[m-1]=l[m-1].se;
	pl[m-1]=l[m-1].fi;
	for(int i=m-2;i>-1;--i)
	{
		prefl[i]=prefl[i+1]+l[i].se;
		pl[i]=l[i].fi;
	}
	prefr[n-1]=r[n-1].se;
	pr[n-1]=r[n-1].fi;
	for(int i=n-2;i>-1;--i)
	{
		prefr[i]=prefr[i+1]+r[i].se;//reversed, so member access is not accurate
		pr[i]=r[i].fi;
	}
	//searching
	ll opt=LLONG_MIN;
	for(int i=0;i<m;++i)f	{
		auto a=prefl[lower_bound(pl,pl+m,pl[i])-pl];
		auto b= prefr[lower_bound(pr,pr+n,sz-pl[i])-pr];
		if(opt<a+b) opt=a+b;
	}

	cout<<opt;

	










}
