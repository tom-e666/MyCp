#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,t;
	cin>>n>>x;
	vector<int> v(n);
	for(auto &i:v) cin>>i;
	//not so good: an nlogn solution
	//or a O(n) solution with minused value? x-v[i] : maximum input?
	sort(v.begin(),v.end());
	int l=0,r=n-1;
	int cnt=0;
	while(l<r)
	{
		if(v[l]+v[r]<=x)
		{
			l++;
			r--;
			cnt++;
		}else
		{
			r--;
			cnt++;
		}
	}
	if(l==r) cnt++;
	cout<<cnt;

}