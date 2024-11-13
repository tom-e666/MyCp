#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	vector<int> a(n,0),b(n,0);
	for(auto &i :a) cin>>i;
	for(auto &i :b) cin>>i;
	int dp[n];
	for(int i=0;i<n;++i){
		dp[i]=b[i];
		int j=i-1;
		while(j>=0){
			if(a[i]-a[j]>=k)
				dp[i]=max(dp[i],dp[j]+b[i]);
			j--;
		}
	}
	cout<<*max_element(dp,dp+n);
}
