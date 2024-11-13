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
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1e9+7;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll sz,m,n;
	cin>>sz>>m>>n;
	vll l(m),r(n);
	
	for(auto &i: l)
		cin>>i.fi;
	for(auto &i: l)
		cin>>i.se;
	sort(all(l));
	for(auto &i: l)
		cin>>i.fi;
	for(auto &i: l)
		cin>>i.se;
	sort(all(l));
	//pref
	vl prefl(m,0),prefr(n,0);
	for(int i=0;i<m;++i)
	{
		prefl[l[i].fi]+=l[i].se;

	}
	for(int i=1;i<m;++i)
	{
		//this part is sole ly magic, not knowing how the fuck people figure it out
		prefl[l[i].fi]=
	}

		




}
