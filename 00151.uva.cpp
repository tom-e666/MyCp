#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define loop(i, a, b) for (int i = a; i < b; ++i)
#define ll long long
#define F first
#define S second
#define pii pair<int, int>
#define vi vector<int>
vi solve(int n, int k)
{
	
}
signed main()
{
	int n;
	while(cin>>n && n)
	{
		int m=2;
		while(1)
		{
			if(josephus(n,m)==13)
			{
				cout<<m<<"\n";
				break;
			}
			else
			{
				++m;
			}
		}
	}
	cerr<<josephus(14,18);
}