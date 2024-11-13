#include<bits/stdc++.h>
using namespace std;
int convert(int a){
    int res=0;
    bool flag=false;
    if(a<0){
    flag=true;
    a=abs(a);
    }
    while(a){
        res=res*10+a%10;
        a/=10;
    }
    if(flag) res=-res;
    return res;
}
int main(){
    vector<int> v;
    int x;
    while(cin>> x){
        v.emplace_back(convert(x));
    }
    auto it= max_element(begin(v),end(v));
    cout<<*it;
    if(v.end()!=find(begin(v),end(v),*it)){
        cout<<"\n";
        while(it!=v.end()){
            cout<<it-v.begin()<<" ";
            it=find(begin(v),end(v),*it);
        }
        
    }
    
    
}