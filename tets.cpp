#include <bits/stdc++.h>
using namespace std;
void maximal(string &s)
{ // 0 non-tolerance
    sort(begin(s), end(s));
    reverse(begin(s), end(s));
    return;
}
int main()
{
    long long x, y, z;
    string s;
    cin >> s;
    x = stoll(s);
    string a = s;
    maximal(a);
    y = stoll(a);
    maximal(s);
    for(auto &i: s){
        if(i!='0' && s[0]>i) swap(s[0],i);
    }
    if(s.size()>1) sort(s.begin()+1,s.end());
    z=stoll(s);
    if (x == y - z)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    cout << y << " " << z;
}