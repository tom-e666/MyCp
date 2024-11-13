#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	ll a[n+1];
	// 1 nếu sort tốt, n nếu sort xấu
	// quan sát cặp liên tiếp-> n-1 cặp, -> đáp án là từ 0<->n-1 + 1
	//index các cặp liên tiếp
	int x;
	for(int i=0;i<n;++i)
	{
		cin>>x;
		a[x]=i;
	}
	long long cnt=1;
	for(int i=0;i<n-1;++i)
	{
		if(a[i]>a[i+1]) cnt++;
	}
	cout<<cnt;

}