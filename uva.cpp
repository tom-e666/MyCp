#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=a;i<b;++i)
#define ll long long
#define F first
#define S second
#define pii pair<int,int>
#define vi vector<int>
struct solver{
	int urow,ucol,udiag1,udiag2,resrow[8];
	void initSolver()
	{
		int a,b;
		cin>>a>>b;
		a-=1;
		b-=1;
		urow=1<<a;
		ucol=1<<b;
		udiag1=1<<(a+b);
		udiag2=1<<(a-b+7);
		fill(resrow,resrow+8,0);
		resrow[b]=a;
		Try(0);
	}
	void Try(int c)
	{
		if(c==8)//popcount==7
		{
			loop(i,0,8)	
			{
				cout<<resrow[i]<<" ";
			}
			cout<<"\n";
			return;
		}
		if(ucol&(1<<c)) return;

		loop(r,0,8)
		{
			if((urow&(1<<r))||udiag1&(1<<(c+r))||udiag2&(1<<(r-c+7))) continue;
			urow^=1<<r;
			udiag1^=1<<(r+c);
			udiag2^=1<<(r-c+7);
			resrow[c]=r;
			Try(c+1);
			urow^=1<<r;
			udiag1^=1<<(r+c);
			udiag2^=1<<(r-c+7);
			resrow[c]=0;
		}
	}

	
};

signed main(){
	int ts;
	cin>>ts;
	while(ts--)
	{
		solver s;
		s.initSolver();
	}
	cout<<"hi";
}