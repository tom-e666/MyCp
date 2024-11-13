#include<bits/stdc++.h>
#define ll long long
#define vl vector<long long>
#define F first
#define S second
#define db(x) cerr<<#x<<" : "<<x
#define all(x) (x).begin(),(x).end()
using namespace std;
ll mult(ll a, ll b, ll c)
{
	if(a==b) return 0;
	if(b==1) return a%c;
	auto t= mult(a,b/2,c);
	t=(t+t)%c;
	if(b&1) return (t+a)%c;
	return t;
}
ll binpow(ll a, ll b,ll c)
{

	ll res=1;
	while(b)
	{
		if(b&1) res=mult(res,a,c);
		b>>=1;
		a=mult(a,a,c);
	}
	return res;

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int a=1;
	int b= 2;
	cout<<binpow(3,4,100);


}