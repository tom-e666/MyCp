#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=a;i<b;++i)
#define ll long long
#define F first
#define S second
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<long long>bool v[9][9];
const int inf=1e9+1;
	int a[1000002];
signed main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	fill(a,a+n+1,0);
	int s=1;
	loop(i,1,7)
	{
		a[i]=s;
		s+=a[i];
	}
	
	loop(i,7,n+1)
	{
		loop(j,1,7)	
			{
				a[i]+=a[i-j];
				a[i]%=(1000000007);
			}
	}
	cout<<a[n];
}