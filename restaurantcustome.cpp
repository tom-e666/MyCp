
#include<bits/stdc++.h>

using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<int> a(n,0),b(n,0);

	for(int i=0;i<n;++i){
		cin>>a[i]>>b[i];
	}
	sort(begin(a),end(a));
	sort(begin(b),end(b));
	int cnt=0,ans=0;
	int i=0,j=0;
	while(i<n &&j<n){
		while(i<n&&a[i]<b[j]){
			cnt++;
			i++;
		}
		ans=max(ans,cnt);
		if(i==n) break;
		while(j<n && a[i]>b[j] ){
			cnt--;
			j++;
		}
	}
	cout<<ans;
	



}