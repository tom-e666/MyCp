#include<bits/stdc++.h>
/*store pair(>10) in a queue and symmetric in a queue*/
using namespace std;

bool issymmetric(unsigned x){
    string a=to_string(x);
    string b=a;
    reverse(begin(b),end(b));
    return a==b;
}

int sum(int x){
    int res=0;
    while(x){
        res+=x%10;
        x/=10;
    }
    return res;
}

int reverseInt(int x){
    int res=0;
    while(x){
        res=res*10+x%10;
        x/=10;
    }
    return res;
}

int main(){
    vector<int> vv;
    int x;
    while(cin>>x) 
        vv.emplace_back(x);
    int n=vv.size();
    sort(begin(vv),end(vv));
    vector<int> res;
    vector<int> symm,v;
    
    for(int i=0;i<n;i++){
        if(issymmetric(vv[i])){
        	symm.emplace_back(vv[i]);
        }else{
        	v.emplace_back(vv[i]);
        }
    }
    n=v.size();
    int mid=0;

        vector<int> straight(v.begin(),v.end());
        vector<int> rev;
        for(auto i: straight){
            rev.emplace_back(reverseInt(i));
        }
        sort(begin(rev),end(rev));
        int i=straight.size();
        int j=straight.size();
        while(i&&j){
            if(straight[i-1]==rev[j-1]){
                res.emplace_back(min(straight[i-1],rev[j-1]));
                i--;j--;
            }else if(straight[i-1]<rev[j-1]){
                j--;
            }else{
                i--;
            }
        }

    for(auto i: res) 
        cout<<i<<" ";
    if(mid) 
        cout<<mid<<" ";
    reverse(begin(res),end(res));
    for(auto i: res) 
        cout<<i<<" ";

    return 0;
}
