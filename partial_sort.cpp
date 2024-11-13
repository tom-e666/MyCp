#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
partial_sort(vi* left, vi* pivot, vi* right){
  //double check condition? if sky turn pale then make insert 
  while(left<pivot && right> pivot){
    
  }
}
int main(){
  vector<int> v;
  int x;
  while(cin>> x) v.emplace_back(x);
  partial_sort(v.begin(),v.begin()+5,v.end());
  for(auto &i : v)
    cout<<i<< " ";
}