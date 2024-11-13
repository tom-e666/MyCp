#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define fi first
#define se second

using namespace std;
const int INF=1e9+7;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	vll v(n);
	for(auto &i:v) cin>>i;
	vll raid(n,0),no_raid(n+1,0);
	raid[0]=v[0];
	raid[1]=v[1]+v[0];
	no_raid[0]=0;
	no_raid[1]=v[0];
	for(int i=2;i<n;++i)
	{
		no_raid[i]=max(raid[i-1],no_raid[i-1]);
		raid[i]=v[i]+max(no_raid[i-1],v[i-1]+no_raid[i-2]);
	}
	no_raid[n]=max(raid[n-1],no_raid[n-1]);
	cout<<no_raid[n];



	




}
