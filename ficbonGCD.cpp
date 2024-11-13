#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll a,b,m;
ll ficc(ll n){
	if(n==1 || n==2) return 1;
	return ficc(n-1)%m+ficc(n-2)%m;
}
ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int main(){
	ios_base::sync_with_stdio(0);

	cin.tie(0);
	cout.tie(0);
	
	cin>>a>>b>>m;
	cout<<ficc(gcd(a,b))%m;




}