#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define rall(x) (x).rbegin(),(x).rend()
using namespace std;
int n, m;
vector<int> h, t,pr;
map<int,bool>d;

int find_pr(int x) {
    if (x == pr[x]) return x;
    pr[x] = find_pr(pr[x]);
    return pr[x];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bool check =false;
    cin >> n >> m;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        h.emplace_back(x);
    }
    sort(all(h));
    for (int i = 0; i < m; ++i) {
        cin >> x;
        t.emplace_back(x);
    }
    pr=vector<int>(n,0); 
    for (int i = 0; i <= n; ++i) {
        pr[i]=i;
    }
    for (auto q : t) 
    {
        auto p = upper_bound(all(h), q)-h.begin();
        p--;
        if(p==-1)
        {
            cout<<"-1\n";
        }else
        {
            int x = find_pr(p);
            if(x==0)
            {
               if(!check) 
               {
                    cout<<h[x]<<"\n";
                    
                    check=true;    
               }else
               {
                   cout<<"-1\n";
               }
               
            }
            else
            {
                pr[x]=x-1; // pr/
                cout<<h[x]<<"\n";
            }
			
        }
    }
    
}
