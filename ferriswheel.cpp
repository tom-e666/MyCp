#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using ll=long long;
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n, x;
    int cnt=0;
    cin>>n>>x;
    vector<int> v(n);
    for(auto &i: v) cin>>i;
    sort(all(v));
    int i=0,j=n-1;
    while(i<j){
        while(i<j &&v[i]+v[j]>x){
            j--;
            cnt++;
        }
        while(i<j && v[i]+v[j]<=x){
            cnt++;
            i++;
            j--;
        }
    }
    if(i==j) cnt++;
    cout<<cnt;





}