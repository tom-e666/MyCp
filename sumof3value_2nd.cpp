#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,x;
	cin>>n>>x;
	vector<int> v(n);
	vector<int> ans;
	for(auto &i:v ) cin>>i;
	vector<int> vv(begin(v),end(v));
	sort(begin(v),end(v));
	for(int a=0;a<n;++a){
		long long t=x-v[a];
		int i=0,j=n-1;
		while(i<j){
			if(1ll*v[i]+v[j]<t){
				i++;
			}else if(1ll*v[i]+v[j]>t){
				j--;
			}else if(i==a){
				i++;
			}else if(j==a){
				j--;
			}else{
				ans=vector<int>{v[a],v[i],v[j]};
				goto label;
			}
		}

	}

	label:
	if(ans.size()==0)cout<<"IMPOSSIBLE";
	else{
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

	}


	
	

}