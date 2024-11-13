/*third trial, correct 2nd trail that uses too much iterator 
and mess up the code*/
#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
int n;
vector<pii> v;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	v.resize(n);
	int x;
	for(int i=0;i<n;++i){
		cin>>x;
		v[i]=pii(x,i);
	}
	sort(all(v),[](pii a,pii b){
		if(a.first==b.first)
			return a.second<b.second;
		return a.first<b.first;
	});
	int res=INT_MAX;
	int i=0;
	cerr<<"1\n";
	while(i<n){
		int key=v[i].first;
		int tmp=v[i].second+1;
		while( i+1<n && v[i+1].first==key){
			tmp=max(tmp, v[i+1].second-v[i].second);
			i++;
		}
		tmp=max(tmp, n-v[i].second);
		res=min(res, tmp);
		i++;
	}
	cout<<res;

	


}