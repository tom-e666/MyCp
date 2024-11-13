#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	vector<pair<int,int>> a(n,{0,0});
	for(int i=0;i<n;++i){
		cin>>a[i].first>>a[i].second;
	}
	auto cmp =[](pii x, pii y)->bool{
		if(x.second==y.second){
			return x.first>y.first;
		}else{
			return x.second<y.second;
		}
	};
	sort(all(a),cmp);
	int t=a[0].second;
	int cnt=1;
	for(int i=1;i<n;++i){
		if(a[i].first>=t){
			cnt++;
			t=a[i].second;
		}
	}
	cout<<cnt;
	

}
/* solution:
	sort asc ending time, then pick by find the first to start, no binary here


*/