/* 
idea:
found hint 1 in cses and solution is found
let yes(t) determine whether t time is enough to produce the 
required products then using binary-search to find the optimized 
solution
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll sum;
ll n,t;

vector<int> v;
bool yes(ll x,ll r=t){ //r is t 
	for(auto i:v) r-=x/i;
	if(r>0) return false;
	return true;
}
#define all(x) begin(x),end(x)
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>t;
	v.resize(n);
	for(auto& i:v) cin>>i;
	sort(all(v));
	long long ans=0;
	for(long long p=1ll*t*v[0]/2;p>0;p/=2){
		while(!yes(ans+p)) ans+=p;
	}
	cout<<ans+1;
	

}