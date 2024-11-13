#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll q,h,s,d,n,w=0,nq=0,nh=0,ns=0,nd=0;
	cin>>q>>h>>s>>d>>n;
	//d
	nd=n/2;
	//s
	ns=n-nd*2;
	if(2*s<d){
		ns+=nd*2;
		nd=0;
	}
	
	//h
	if(2*h<s){
		nh+=2*ns;
		ns=0;
	}
	if(4*h<d){
		nh+=4*nd;
		nd=0;
	}


	//q
	if(2*q<h){
		nq+=2*nh;
		nh=0;
	}
	if(4*q<s){
		nq+=4*ns;
		ns=0;
	}
	if(8*q<d){
		nq+=8*nd;
		nd=0;
	}
	cout<<q*nq+h*nh+s*ns+d*nd;
	



	








}