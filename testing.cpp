#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define loop(i,a,b) for(int i=a;i<b;++i)
#define ll long long
#define F first
#define S second
#define pii pair<int,int>
#define vi vector<int>
#define vll vector<long long>

signed main()
{
	bool isafter=false;
	int n;
	while(cin>>n)
	{
		if(n==0) break;
		if(isafter)
		{
			cout<<"\n";
		}else
		{
			isafter=true;
		}
		bool check=0;
		loop(b,1234,98765/n+1)
		{
			int a=b*n;
			int t=0;
			if(a<10000 ||b<10000)
				t=1;
			int x=a;
			while(x)
			{
				t|=(1<<(x%10));
				x/=10;
			}
			x=b;
			while(x)
			{
				t|=(1<<(x%10));
				x/=10;
			}

			if(__builtin_popcount(t)==10)
			{
				string as=to_string(a);
				string bs=to_string(b);
				if(a<10000)as='0'+as;
				if(b<10000)bs='0'+bs;
				cout<<as<<" / "<<bs<<" = "<<n<<"\n";
				check=1;
			}

		}
		if(!check) cout<<"There are no solutions for "<<n<<".\n";
		
	}

	


}