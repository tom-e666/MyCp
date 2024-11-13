#include<bits/stdc++.h>
using namespace std;
const int m=1e9+7;
int mult(int a, int b, int m=m){
	if(b==0) return 0;
	if(b==1) return a%m;
	int t=mult(a,b/2);
	t=(t+t)%m;
	if(b&1) return (t+a)%m;
	return t;
}
int xpow(int a, int b, int m=m)
{
	if(b==0) return 1;
	if(b==1) return a%m;
	int t=xpow(a,b/2);
	t=mult(t,t);
	if(b&1)
	{
		return mult(t,a);
	}
	return t;
}
int main(){
	int n;
	cin>>n;
	cout<<xpow(2,n);
}