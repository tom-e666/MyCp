#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,x;
	cin>>n>>x;
	vector<int> v(n);
	for(auto &i: v) cin>>i;
	vector<int> vv(begin(v),end(v));
	sort(begin(v),end(v));
	vector<int> ans;
	long long sum;
	for(int i=0;i<n;++i)
		for(int j=n-1;j>=i-3;j--){
			sum=x-v[i]-v[j];
			int x=i+1;
			int y=j-1;
			while(x<y){
				if(v[x]+v[y]>sum){
					y--;
				}else if(v[x]+v[y]<sum){
					x++;
				}else{
					ans=vector<int>{v[i],v[j],v[x],v[y]};
					goto label;
				}
			}
		}
		label:
		if(ans.size()){
			auto x=find(begin(vv),end(vv),ans[0]);
			int y=x-vv.begin();
			cout<<y+1<<" ";
			*x=-1;
			x=find(begin(vv),end(vv),ans[1]);
			y=x-vv.begin();
			cout<<y+1<<" ";
			*x=-1;
			x=find(begin(vv),end(vv),ans[2]);
			y=x-vv.begin();
			cout<<y+1<<" ";
			*x=-1;
			x=find(begin(vv),end(vv),ans[3]);
			y=x-vv.begin();
			cout<<y+1<<" ";
			*x=-1;
		}else{
			cout<<"IMPOSSIBLE";
		}
}