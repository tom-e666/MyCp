#include<bits/stdc++.h>
using namespace std;
void line(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);for(auto &i: v){
        cin>>i;
        i=k-(i%k); //needed for increment;
    }
    if(k==2 ||k==3||k==5){
        cout<<*min_element(v.begin(),v.end())<<"\n";
    }else{
        k==4;
        //the only contrary is when 4k+1 (3) is the smallest 
        // then if exists another 4k+1 then 2 is right, not 3;
        int x=*min_element(v.begin(),v.end());
        if(x==0 ||x==1){
            cout<<x<<"\n";
        }else if(x==2){
            v.erase(find(v.begin(),v.end(),x));
            auto it=min_element(v.begin(),v.end());
            if(it!=v.end()){
                if(*it==2)
                cout<<"0\n";
                else if(*it==3)
                cout<<"1\n";
            }else{
                cout<<"2\n";
            }
        }else if(x==3){
            auto it=min_element(v.begin()+1,v.end());
            if(it!=v.end() && *it==3){
                cout<<"2\n";
            }else{
                cout<<"3\n";
            }
            
        }
    }
    
    
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        line();
    }
}