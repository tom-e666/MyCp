#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	if(n%4==1 ||n%4==2){
		cout<<"NO";
		return 0;
	}else{
		cout<<"YES"<<"\n";
		if(n%4==0){
			cout<<n/2<<"\n";
			for(int i=1;i<=n;i+=4) cout<<i<<" ";
			for(int i=4;i<=n;i+=4) cout<<i<<" ";
			cout<<n/2<<"\n";
			for(int i=2;i<=n;i+=4) cout<<i<<" ";
			for(int i=3;i<=n;i+=4) cout<<i<<" ";
		}else if(n%4==3){
			cout<<(n+1)/2<<"\n";
			int a=1;
			
			for(int i=1;i<=(n+1)/4;++i){
				cout<<a<<" ";
				a+=2;
			}
			a-=1;
			for(int i=1;i<=(n+1)/4;++i){
				cout<<a<<" ";
				a+=2;
			}
			cout<<"\n"<<n/2<<"\n";
			a=2;
			for(int i=1;i<=n/4;++i){
				cout<<a<<" ";
				a+=2;
			}
			a+=1;
			for(int i=1;i<=(n+1)/4;++i){
				cout<<a<<" ";
				a+=2;
			}

		}
	}

}