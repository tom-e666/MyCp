#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vll vector<vector<long long>>
#define fi first
#define se second

#define loop(i,a,b) for(int i=a;i<b;++i)
#define all(x) (x).begin(),(x).end()
#pragma GCC optimize("O3")
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   	int n,k;
   	cin>>n>>k;
   	if(k==1){
   	    cout<<n;
   	    return 0;
   	}
   	int a[n];
   	for(int i=0;i<n;++i)
   	    cin>>a[i];
   	//inital 0-r
   	//exceed k then o-> l and r->R
   	//l-R 
   	//til R=n then end
   	//l-r-> n, r-l+1...0 intersect when new l<r: - 
   	// new r-> new res, 
   	vector<long long> mempos(11,-1);
   	ll res=0;
   	ll l=0,ck=0;
   	ll cnt=0;
   	for(int r=0;r<n;++r)
   	{
   	    if(mempos[a[r]]<l)
   	    {
   	        ck++;
   	    }
   	    mempos[a[r]]=r;
   	    if(ck>k)
   	    {
   	        //increase l to remove an element
   	        //find a value that should be removed: which is a[l]=mempos[]
   	        while(l!=mempos[a[l]]) l++;
   	        l++;
   	        ck--;
   	    }
   	    res+=r-l+1;
   	    
   	}
   	cout<<res;
}