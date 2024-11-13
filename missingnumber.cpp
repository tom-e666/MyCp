#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int> a(n-1);
    for(int i=0;i<n-1;++i){
        cin>>a[i];
    }
    sort(begin(a),end(a));
    for(int i=0;i<n-1;++i){
        if(a[i]!=i+1){
            cout<<i+1;
            return 0;
        }
    }
    cout<<n;


}