#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;++i) cin>>v[i];
    sort(v.rbegin(),v.rend());
    int p=find(begin(v),end(v),v[k-1])-v.begin();
    if(v[p]==0){
        while(p>=0 && v[p]==0) p--;
        cout<<p+1;
    }else{
        while(p+1<n && v[p+1]==v[p]) p++;
        cout<<p+1;
    }
    
    
    
}
