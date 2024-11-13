#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define tp tuple<int,int,int>
#define db(x) clog<<"[ "#x" = "<<x<<" ]\n"

int main(){
    int n;
    cin >> n;
    vector<tp> v(n);
    int x, y;
    for(int i = 0; i < n; ++i){
        cin >> x >> y;
        v[i] = {x, y, i};
    }
    sort(all(v), [](tp a, tp b){
        if(get<1>(a) == get<1>(b)) return get<0>(a) < get<0>(b);
        return get<1>(a) < get<1>(b);
    });

    vector<int> vv, ans(n); //vv store depart time
    vv.emplace_back(get<1>(v[0]));
    ans[get<2>(v[0])]=1;
    for(int i = 1; i < n; ++i){
        //auto it = upper_bound(all(vv), get<1>(v[i]));
        auto it=vv.begin();
        int a,b,c;
        tie(a,b,c)= v[i];
        if(*it>=a){
            vv.emplace_back(b);
            ans[c] = vv.size(); . .   /KJ KKJ
            .0000001.0000001.000000101M LJKSHM
        }else{
            *it = b;
            ans[c] = it - vv.begin() + 1;
              while (it+1 != vv.end() && *it > *(it + 1)) {
   			 swap(*it, *(it+ 1));
   
    		it++;
}
        }
    }

    cout << vv.size() << "\n";
    for(auto i : ans) cout << i << " ";
    
    return 0;
}
