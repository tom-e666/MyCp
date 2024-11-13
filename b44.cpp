#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin>>n>>m;
    // 1 nếu sort tốt, n nếu sort xấu
    // quan sát cặp liên tiếp-> n-1 cặp, -> đáp án là từ 0<->n-1 + 1
    //index các cặp liên tiếp
   ll idx[n+1];
   ll val[n+1];
   for(int i=1;i<=n;++i)
   {
    cin>>val[i];
    idx[val[i]]=i;
   }
   ll cnt=1;
   for(int i=1;i<n;++i)
   {
    if(idx[i]>idx[i+1])
    {
        cnt++;
    }
   }
   //cnt xong
   // query
   // p,q-> v[p],v[q]-> a[v[p]], a[v[q]]-> update
   int x,y;

   while(m--)
   {
    cin>> x>>y;
    if(val[y]<val[x]) swap(x,y);
    if(val[y]-val[x]==1)
    {
        int k=val[x];
    if(k>1 && idx[k-1]>idx[k]) cnt--;
    if(k<n && idx[k]>idx[k+1]) cnt--;
    k=val[y];
    if(k>1 && idx[k-1]>idx[k]) cnt--;
    if(k<n && idx[k]>idx[k+1]) cnt--;
    if(idx[val[x]]>idx[val[y]]) cnt++;
    swap(idx[val[x]],idx[val[y]]);
    swap(val[x],val[y]);
    k=val[x];
    if(k>1 && idx[k-1]>idx[k]) cnt++;
    if(k<n && idx[k]>idx[k+1]) cnt++;
    k=val[y];
    if(k>1 && idx[k-1]>idx[k]) cnt++;
    if(k<n && idx[k]>idx[k+1]) cnt++;
    if(idx[val[y]]>idx[val[x]]) cnt--;
    cout<<cnt<<"\n";
        continue;
    }
    int k=val[x];
    if(k>1 && idx[k-1]>idx[k]) cnt--;
    if(k<n && idx[k]>idx[k+1]) cnt--;
    k=val[y];
    if(k>1 && idx[k-1]>idx[k]) cnt--;
    if(k<n && idx[k]>idx[k+1]) cnt--;
    swap(idx[val[x]],idx[val[y]]);
    swap(val[x],val[y]);
    k=val[x];
    if(k>1 && idx[k-1]>idx[k]) cnt++;
    if(k<n && idx[k]>idx[k+1]) cnt++;
    k=val[y];
    if(k>1 && idx[k-1]>idx[k]) cnt++;
    if(k<n && idx[k]>idx[k+1]) cnt++;
    cout<<cnt<<"\n";

   }




}