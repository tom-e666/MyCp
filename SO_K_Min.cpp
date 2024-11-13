#include<bits/stdc++.h>
/*solut9in 2: notice every value eg:153, and its co_position
already decide local minimal k' , so we should find k' and 
choose the global minimal */
using namespace std;
#define dg(x) cerr<<"[ "#x" = "<<x<<" ]\n"
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
vector<pii> v;
int n;
int lg=0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	v.resize(n);
	int x;
	for(int i=0;i<n;++i){
		cin>>x;
		v[i]=pii(x,i);
	}
	sort(all(v),[](pii a, pii b)->bool{
		if(a.first==b.first)
			return a.second<b.second;
		return a.first<b.first;
	});
	auto it_t=equal_range(all(v),pii(0,0));// any;
	auto fk=[](decltype(it_t) pit)->int{//find k
		//if(it->first==it->second)//omit
		if( pit.second - pit.first == 1)
		{
			// whether the range of co_position included 1 member, 1..k..n
			int k=pit.first->second;
			return max(k+1,n-k);	
		} 
		cerr<<"log""\n";
		int l=pit.first->second;
		auto i=pit.first+1;	
		int res=l+1;
		cerr<<"log""\n";
		for(;i!=pit.second;i++){
			res=max(res, (i->second-l+1)/2);
			l=i->second;
			cerr<<"log""\n";
		}
		cerr<<"log""\n";
		res=max(res, n-prev(i)->second);
		return res;
	};
	
	int res=INT_MAX;
	auto it= v.begin();
	while(it!=v.end()){
		
		auto p=equal_range(all(v),pii(it->first,INT_MIN));

		res=min(res,fk(p));

		it=p.second;

	}
	cout<<res;
}