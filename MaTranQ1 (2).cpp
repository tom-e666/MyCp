#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int n,a;
	cin>>n>>a;
	int arr[n][n];
	for(int i=0;i<n;++i)
		for(int j=n-1;j>=0;--j){
			arr[i][j]=a++;
		}
	for(int i=1;i<n;i+=2){
		for(int j=n-1;j>=0;--j){
			cout<<arr[j][i]<<" " ;
		}
		cout<<'\n';
	}
	int _min=INT_MAX;
	for(int i=0;i<n;++i){
	if(arr[i][n-1]%2==1)	_min=min(_min,arr[i][n-1]);
	}
	if(_min!=INT_MAX){
		cout<<_min<<"\n";
	}else{
		cout<<"NULL\n";
	}
	int sum=0;
	if(arr[0][0]%2==0) sum+=arr[0][0];
	{
	if(n==1) {
		cout<<sum;
		return 0;
	}
	if(arr[0][n-1]%2==0) sum+=arr[0][n-1];
	if(arr[n-1][0]%2==0) sum+=arr[n-1][0];
	if(arr[n-1][n-1]%2==0) sum+=arr[n-1][n-1];
	}
	cout<<sum;

}
