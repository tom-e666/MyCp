#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
using namespace std;
int m,n;
vi r,x;
bool Try(int t)
{
	//greedy left;
	int trash=0;
	for(int i=0;i<m;++i)
	{
		
		if(x[trash]<r[i])
		{
			if(x[trash]<r[i]-t) return false;
			int rr=max(x[trash]+x[trash]-r[i]+t,r[i]+(t+x[trash]-r[i])/2);
			while(trash<n && x[trash]<=rr) trash++;
		}
		 else
		 {
			 while(trash<n && x[trash]<=r[i]+t) trash++;
		}
	}
	//look 
	if(trash==n) return true;
	return false;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ifstream("GARBOT.INP");
	ofstream("GARBOUT.OUT");
	cin>>m>>n;
	 r.resize(m),x.resize(n);//robot, rac
	for(auto &i:r) cin>>i;
	for(auto &i:x) cin>>i;
	sort(r.begin(),r.end());
	sort(x.begin(),x.end());
	int t=0;
	for(int p=n/2;p>0;p/=2)
	{
		while(!Try(t+p)) t+=p;
	}
	cout<<t+1;
}
