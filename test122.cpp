#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
struct g{
    int v;
    int s;
    vector<pii> e;
    void in(){
        int nv,ne;
        cin>>v>>ne>>s;
        int a, b;
        while(ne--){
            cin>>a>>b;
            e.emplace_back(pii(a,b));
        }
    }
    void dfs(){
    sort(begin(e),end(e),[](pii a, pii b){
        if(a.first==b.first) return a.second>b.second;
        return a.first<b.first;
    });
    vector<bool> visited(v,false);
    stack<int> st;
    st.push(s);
    visited[s-1] = true; 
    while(!st.empty()){
        auto i= st.top();
        cout<<i<<" ";
        st.pop();
        for(auto ed: e){
            if(ed.first==i && !visited[ed.second-1]){
                st.push(ed.second);
                visited[ed.second-1]=true;
                
            }
        }
    }
}
};
int main(){
    g a;
    a.in();
    a.dfs();
}