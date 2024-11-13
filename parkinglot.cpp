#include<bits/stdc++.h>
using namespace std;
#define ll long long
uint64_t p[31];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	uint64_t res=0;
	p[1]=1;
	p[0]=1;
	for(uint64_t i=2;i<=30;++i)
		{
			p[i]=p[i-1]*i;
		}
	res+=4LL*3*p[n-3]*2;
	for(int i=2;i<n-1;++i)
		{
			res+=3*p[i-2]*3*p[n-3-i];
		}
		cout<<res;


}