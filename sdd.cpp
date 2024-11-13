#include<bits/stdc++.h>
#define db(x) clog<<"[ "#x" = "<<x<<" ]\n"
using namespace std;
int main(){
    int x,n;
    cin>>x>>n;
    
    double t=x,s=1+x;
    for(int i=1;i<=n;++i){
        t=t*x*x;
        t=t/(2*i)/(2*i+1);
        s+=t;
        db(s);
    }
    cout<<fixed<<setprecision(3)<<s;
    
}