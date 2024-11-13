/* upcoder codename: "jr"
   solution: 
   -> base on example the regtangle that its edges parallel
   to the xOy bases is first recognized. 2nd, takes notice 
   on the one that resembles diamond shape: every one this kind 
   may have 1 and only one normal regtangle covering it,so with 
   every sub regtangle that n>2, we count it as 2 for each.*/
#include<bits/stdc++.h>
using namespace  std;
const int m=1e9+7;
int xpow(int x, int n ){
	if(n==0) return 1;
	if(n==1) return x%m;
	int a=xpow(x%m,n/2);
	if(n&1)
		return ((((a%m)*(a%m))%m)*x)%m;
	return ((a%m)*(a%m))%m;
}

int ans=0;
int n;
void fn(){
	//sz =2, 3->n;
	ans+=xpow(n-1,2);
	ans%=m;
	for(int i=3;i<=n;++i){
		ans+=(xpow(n-i+1,2)*2)%m;
		ans%=m;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	fn();
	cout<<ans<<endl;

}