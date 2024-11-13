#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    int a[n];//a: desire, b: size
    int b[m];
    for(auto &i:a) cin>>i;
    for(auto &i:b) cin>>i;
    sort(a,a+n);
    sort(b,b+m);
    int i=0;
    int cnt=0;
    for(auto j:b){
        while(a[i]<j-k&& i<n)
            i++;
        if(i>=n) break;
        if(abs(a[i]-j)<=k){
            i++;
            cnt++;
            continue;
        }
    }
    cout<<cnt;
   }