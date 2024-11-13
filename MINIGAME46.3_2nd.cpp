#include<bits/stdc++.h>
using namespace std;
#define db(x) cerr<< "[ "#x" = "<<x<<"] "
#define all(x) (x).begin(),(x).end()
#define pis pair<int,string> 
#define f first
#define s second

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector<string> v(k+1,"zzzzzzzzz");
    vector<bool> exist(k+1,false);
    exist[0]=true;
    v[0]="";
    string s;
    for(int i=0;i<n;++i){
        cin>>s;
        int sz=s.size();
        for(int i=k-sz;i>=0;i--){
            if(exist[i]){
                if (v[i]+s < v[i+sz])
                {
                    v[i+sz]=v[i]+s;
                    exist[i+sz]=1;
                }
            }
        }
    }
    cout<<v[k];
}
