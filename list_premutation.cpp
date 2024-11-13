#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> res;
void permutation(vector<int>&v,int s, int e){
   if(s==e){
      res.emplace_back(v);
      return;
   }
   for(int i=s;i<e;++i){
      swap(v[s],v[i]);
      permutation (v, s+1,e);
      swap(v[s],v[i]);
   }
}
int main(){
   vector<int> v;
   v.reserve(100);
   int x;
   while(cin>>x){
      v.emplace_back(x);
   }
   permutation(v,0,v.size());
   cout<<res.size()<<"\n";
   for(auto vec:res)
   {
      for(auto i: vec) cout<<i;
         cout<<"\n";
   }

}