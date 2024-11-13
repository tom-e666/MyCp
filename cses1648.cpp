#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
vector<long long> smt;
void construct(int v, int tl, int tr){
	if(tl==tr)
	{
		smt[v]=a[tl];
	}
	else
	{
		int tm=(tl+tr)/2;
		construct(v*2, tl,tm);
		construct(v*2+1,tm+1, tr);
		smt[v]=smt[2*v]+smt[2*v+1];
	}
}
void update(int v, int tl, int tr, int pos, int value){
	if(tl==tr)
	{
		smt[v]=value;
	}else
	{	
		int tm=(tl+tr)/2;
		if(tm>=pos)
			update(2*v ,tl, tm , pos, value);
		else
			update(2*v+1,tm+1,tr, pos, value);
		smt[v]=smt[2*v]+smt[2*v+1];
	}
}
long long sum(int v, int tl, int tr, int l, int r){
	if(l>r)
		return 0;
	if(tl==l && tr==r)
	{
		return smt[v];
	}
	int tm=(tl+tr)/2;

	return sum(2*v, tl, tm, l,min(tm,r))
		+  sum(2*v+1,tm+1,tr,max(l, tm+1),r);
}

int main(){
	
	int q;
	cin>>n>>q;
	//should remove a
	a.resize(n);
	smt.resize(4*n);
	for(int i=0;i<n;++i) cin>>a[i];
	construct(1,0,n-1);
	int a,b,c;
	while(q--){
		cin>>c>>a>>b;
		if(c==1){
			update(1,0,n-1,a-1,b);
		}else{
			cout<<sum(1,0,n-1,a-1,b-1)<<"\n";
		}
	}
}