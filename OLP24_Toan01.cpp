#include<bits/stdc++.h>
using namespace std;
const int m=10;
int pow2(long long cap)
{   if(cap==1) return 2;
    int t=pow2(cap/2);
    t=t*t;
    t%=10;
    if(cap&1){
        return (t*2)%10;
    }
    return t;
}
int main()
{
    long long n;
    cin>>n;
    auto t=pow2(n);
    cout<<(t+1)%10;
}