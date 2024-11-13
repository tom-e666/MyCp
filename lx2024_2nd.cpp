/* go with traditional solution, sort and add up the right side
sort the answer for binary search score 7/10, last 3 meets LTE*/
/* path compression_ union_find implementation, used with
distance calculation*/
#include<bits/stdc++.h>
#define db(x) clog<<"[ "#x" = "<<x<<" ]"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pil pair<int,ll>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int r,m,n;
	cin>>r>>m>>n;
	vector<int> v(m);
	for(auto&i: v) cin>>i;
	unordered_map<int,ll> mpr;
	int x;
	for(auto &i: v){
		cin>>x;
		mpr[i]+=x;
	}
	vector<pil>vr;
	for(auto i: mpr){
		vr.emplace_back(pil{i.first,i.second});
	}
	sort(all(vr));
	int k=vr.size();
	for(int i=k-1;i>0;--i){
		vr[i-1].second+=vr[i].second;
	}
	v.resize(n);
	for(auto &i: v) cin>>i;
	unordered_map<int,ll> mpl;
	for(auto &i:v){
		cin>>x;
		mpl[i]+=x;
	}
	vector<pil> vl;
	for(auto i: mpl){
		vl.emplace_back(pil{i.first,i.second});
	}
	sort(all(vl));
	k=vl.size();
	for(int i=k-1;i>0;--i){
		vl[i-1].second+=vl[i].second;
	}
	long long ans=0;
	for(auto i: vl){
		auto it=lower_bound(all(vr),pil{r-i.first,0});
		if(it==vr.end()){
			ans=max(ans, i.second);
		}else{
			ans=max(ans, i.second+it->second);
		}
	}
	cout<<ans;



	


}