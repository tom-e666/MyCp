#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(((a%3)+(b%3))%3==0)
		{
			if(a==0 && b==0) {
				cout<<"YES\n";
			}else if(a==0 || b== 0 || a>2*b ||b>2*a)
			{
				cout<<"NO\n";
				
			}
			else
			{
				cout<<"YES\n";
				
			}
			
		}else
		{
			cout<<"NO\n";
		}
	}
}