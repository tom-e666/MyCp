#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
int main()
{
	set<int> s;
	for(int i=0;i<10;++i) s.insert(10-i);
	cout<<*s.begin();
}
