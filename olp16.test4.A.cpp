#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
	int n;
vector<int> v;
vector<int> dp;
vector<int> dpr;
int res=INT_MIN;
// cases: 2 var find, 3 var find, 1 val find
void div3(int l, int r){
	int m=l+ (r-l)/2;
	//3 var;
	con3(l,m);
	con3(m,r);
	
	auto cmp1 =[](pii x, pii y, int start=1)->bool{
		return start*x.first+(start+1)*x.second<start*u.first+(start+1)*y.second;
	}
	auto con2 =[](int lx, int rx)->pii{
		
	}
	//2 left
	
	//2 right

}
void con3(int l, int r){
	if(r-l < 2) return;
	if(r-l ==2){
		res= max( res, v[l],v[l+1]*2,v[l+2]*3);
		return;
	} 
	div3(l,r);
}


int  main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	v.resize(n);

	for(auto & i: v) cin>>i;
		dp.resize(n);
		dpr.resize(n);
	dp[0]=v[0];
	for(int i=1;i<n;++i) dp[i]=max(dp[i-1],v[i]);
	dpr[n-1]=v[n-1];
	for(int i=n-2;i>=0;--i) dp[i]=max(dp[i+1],v[i]);





		


