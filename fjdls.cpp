#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define loop(i, a, b) for (int i = a; i < b; ++i)
#define ll long long
#define F first
#define S second
#define pii pair<int, int>
#define vi vector<int>
const int mod=1e9+7;
int main()
{
	//angry birds
	int t;
	int a,b,c;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c;
		if(c==0)
		{
			cout<<"NO CURVE\n";
		}else if (c>0)
		{
			cout<<"CURVE UP\n";
		}
		else cout<<"CURVE DOWN\n";
	}
}