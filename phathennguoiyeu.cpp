#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, a;
	cin>>n>>a;
	vector<vector<int>> v(n,vector<int>(n));
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			v[i][j]=a;
			a+=2;
		}
	}
	{
		//a
		for(int i=0;i<n;i+=2){
			for(int j=0;j<n;++j){
				cout<<v[j][i]<<" ";
			}
			cout<<"\n";
		}
	}
	// {
	// 	//b
	// 	int k=((n%2==0)?n:n-1);
	// 	int ans=a-2;
	// 	for(int j=0;j<n;++j){
	// 		if(v[j][k]%2==0){
	// 			ans=max(ans,v[j][k]);
	// 		}
	// 	}
	// 	if(ans!=a-2){
	// 		cout<<ans<<"\n";
	// 	}else{
	// 		cout<<"NULL";
	// 	}

	// }
	// {
	// 	//c
	// 	bool check=false;
	// 	if(n==1) 1;
	// 		else{
	// 	int x=n;
	// 	int y=1;
	// 	while( x>=1||y<=n){
	// 		check=1;
	// 		cout<<'('<<x<<','<<y<<')';
	// 		x--;
	// 		y++;
	// 	}
	// }
	// 	if(!check){
	// 		cout<<"NULL";
	// 	}
	// }

}