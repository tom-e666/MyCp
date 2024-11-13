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
        return get<1>(a) > get<1>(b);
    });

    vector<int> vv, ans(n); //vv store start time
    for(int i = 0; i < n; ++i){
        auto it = upper_bound(all(vv), get<1>(v[i]));
        auto it=vv.begin();
        int a,b,c;
        tie(a,b,c)= v[i];
        if(it == vv.end()){
            vv.emplace_back(a);
            ans[c] = vv.size();
        }else{
            *it = a;
            ans[c] = it - vv.begin() + 1;
            sort(all(vv));
            while (it != vv.begin() && *it < *(it - 1)) {
   			 swap(*it, *(it - 1));
   			 
    		it--;
}
        }
    }

    cout << vv.size() << "\n";
    for(auto i : ans) cout << i << " ";
    
    return 0;
}
