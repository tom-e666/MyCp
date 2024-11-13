#include<bits/stdc++.h>
using namespace std;
int main()
{
	
int n;
cin>>n;
int ith=1;
while(n--)
{
	int a,b,c;
	cin>>a>>b>>c;
	//a>b>c;
	
	if(a<b) swap(a,b);
	if(c>b) {
		swap(b,c);
		if(a<b) swap(a,b);
	}
	cout<<"Case "<<ith++<<": "<<b<<"\n";
}
}