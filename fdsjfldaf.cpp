#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
struct cus{
	int l;
	int r;
	int idx;
	int roomid;
	bool operator< (const cus &a) const
	{
		return r<a.r;
	};
	bool operator <(const int &a) const
	{
		return r<a;
	}
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    cus a[n];
    for(int i=0;i<n;++i)
    {
    	cin>>a[i].l>>a[i].r;
    	a[i].idx=i;
    	a[i].roomid=0;
    }
    sort(a,a+n);
    set<cus> s;

    int cnt=1;
    a[0].roomid=1;
    s.insert(a[0]);
    for(int i=1;i<n;++i)
    {
    	//tim so be hon
    	auto it=lower_bound(s.begin(),s.end(),a[i].l);
    	if(it==s.begin()){
    		cnt++;
    		a[i].roomid=cnt;
    		s.insert(a[i]);
    	}else
    	{
    		it=prev(it);
    		a[i].roomid=it->roomid;
    		s.erase(*it);
    	}
    }
    int res[n];
   	for(int i=0;i<n;++i)
   	{
   		res[a[i].idx]=a[i].roomid;
   	}
   	cout<<cnt<<"\n";
   	for(int i=0;i<n;++i)
   		cout<<res[i]<<" ";
   	
}
