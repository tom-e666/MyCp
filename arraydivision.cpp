/*
solution: using valid(int ans) that suggest whether ans, or ans+1 can be a valid idea
maintain dp[]:culmulative sum of values;
*/
#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
vector<long long> s;
int n,k;
bool fn(long long ans){
	if(ans*k<s[n-1]) return false;
	vector<long long>::iterator x;
	long long last_sum=0;
	for(int j=0;j<k;++j){
		x=upper_bound(all(s),ans+last_sum);
		if(x==s.end()) return true;
		x=prev(x);
		last_sum=*x;
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>k;
	vector<int>v(n);
	s.resize(n);
	for(auto &i:v) cin>>i;
	s[0]=v[0];
	for(int i=1;i<n;++i){
		s[i]=s[i-1]+v[i];
	}
	long long ans=0;// ans between s[n-1]/k and inf
	for(int p=s[n-1]/k;p>0;p/=2){
		while(!fn(ans+p)){ ans+=p;}
	}
	cout<<ans+1;


	

}