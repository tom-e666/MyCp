#include<bits/stdc++.h>
using namespace std;
struct circle{
    int x,y,r;
    circle(int a=0, int b=0, int c=0): x(a),y(b),r(c){};
    friend double dis(circle a, circle b){
        double xx=a.x-b.x;
        double yy=a.y-b.y;
        return sqrt(xx*xx +yy*yy);
    }
    friend istream& operator>>(istream & is ,circle & c){
        is>>c.x>>c.y>>c.r;
        return is;
    }
};
 bool intersect(circle a, circle b){
        double d=dis(a,b);
        return abs(a.r-b.r)< d && d< abs(a.r+b.r);
    }   
int main(){
    int n;
    cin>>n;
    int cnt=0;
    vector<circle> v(n);
    for(auto &i:v) cin>>i;
    for(int i=0;i<n;++i) 
        for(int j=i+1;j<n;++j)
            if(intersect(v[i],v[j])) cnt++;
    cout<<cnt;
}