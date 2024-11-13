#include<bits/stdc++.h>
using namespace std;
int n;
std::vector<long long> v;
long long res;
long long S;
long long t=0;
void Try(int x)
{
	if(x==n) 
	{
		res=min(res,abs(S-2*t));
		return ;
	}
	t+=v[x];
	Try(x+1);
	t-=v[x];
	Try(x+1);
}
int main()
{
	
	cin>>n;
	v.resize(n);
	for(auto &i:v) cin>>i;
	S=res=accumulate(v.begin(),v.end(),0LL);
	//first solution: creating sum! not good
	//second: dynamically update the sum;
	Try(0);
	cout<<res;


}