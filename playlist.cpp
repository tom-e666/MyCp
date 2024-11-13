/*
solution: dp construct the available answer ends at
current iterator, maintain a sclicing window of i,j
when advancing j, update if j is used, if last[j]<i
then continue, if last j>i then update i=last[j]+1;last[j]=j
*/
#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int> v(n+1,0);
    v[0]=-1;
    for(int i=1;i<=n;++i){
        cin>>v[i];
    }
    int i=1,j=1;
    map<int,int>last;
    last[v[j]]=j;
    vector<int> ans(n+1,0);
    ans[1]=1;
    for(j=j+1;j<=n;++j){
        if(auto x=last[v[j]];x>=i){
            i=x+1;
        }
        last[v[j]]=j;
        ans[j]=j-i+1;
    }
    cout<<*max_element(all(ans));





}